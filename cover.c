/**
 *
 * @copyright:
 * @file: cover.c
 * @since: 2017-09-24
 * @author: czq | 7160844@qq.com
 * @description:
 *    集合覆盖问题的函数实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-24        1.0             开始创建
 *
 **/

#include <stdlib.h>
#include "cover.h"
#include "linkList.h"
#include "set.h"

int cover(Set *members, Set *subsets, Set *covering)
{
    Set interSection;
    KSet *subset;
    ListElmt *member, *maxMember;
    void *data;
    int maxSize;

    setInit(covering, subsets->match, NULL);

    while (setSize(members) > 0 && setSize(subsets) > 0)
    {
        /* Find the subset that covers the most members.  */
        maxSize = 0;
        for (member = listHead(subsets); member != NULL;
             member = listNext(member))
        {
            if (0 != setIntersection(&interSection,
                &((KSet *)listData(member))->set, members))
                {
                    return -1;
                }
            if (setSize(&interSection) > maxSize)
            {
                maxMember = member;
                maxSize = setSize(&interSection);
            }

            SetDestroy(&interSection);
        }

        /* A covering is not possible if there was no intersection. */
        if (0 == maxSize)
        {
            return 1;
        }

       subset = (KSet *)listData(maxMember); 

       /* Insert the selected subset into the covering. */
       if (0 != setInsert(covering, subset))
       {
           return -1;
       }

       /* Remove each covered member from the set of noncovered members. */
       for (member = listHead(&((KSet *)listData(maxMember))->set);
           NULL != member; member = listNext(member))
       {
           data = listData(member);
           if (0 == setRemove(members, (const void **)data) &&
               NULL != members->destroy)
           {
              members->destroy(data); 
           }
       }

       /* Remove the subset from the set of candidate subsets. */
       if (0 != setRemove(subsets, (void **)&subset))
       {
           return -1;
       }
    }

    /* No covering is possible if there are still noncoverd members. */
    if (setSize(members) > 0)
    {
        return -1;
    }

    return 0;
}
