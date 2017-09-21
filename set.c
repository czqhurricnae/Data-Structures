/**
 *
 * @copyright:
 * @file: set.c
 * @since: 2017-09-17
 * @author: czq | 7160844@qq.com
 * @description:
 *    集合抽象数据结构的函数实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-17        1.0             开始创建
 *
 **/

#include <stdlib.h>
#include <string.h>
#include "linkList.h"
#include "set.h"

void setInit(Set *set, int (*match)(const void *key1, const void *key2),
    void (*destroy)(void *data))
{
   listInit(set, destroy);
   set->match = match;

   return;
}

int setInsert(Set *set, const void *data)
{
    if (setIsMember(set, data))
    {
        return 1;
    }

    return listInsertNext(set, listTail(set), data);
}

int setRemove(Set *set, const void **data)
{
   ListElmt *member, *previous;

   /* Find the member to remove. */
   previous = NULL;

   for (member = listHead(set); NULL != member; member = listNext(member))
   {
       if (set->match((const void *) data, (const void *) listData(member)))
       {
           break;
       }
       previous = member;
   }

   /* Return if the member was not found. */
   if (NULL == member)
   {
       return -1;
   }

   /* Remove the member. */
   return listRemoveNext(set, previous, data);
}

int setUnion(Set *setu, const Set *set1, const Set *set2)
{
   ListElmt *member;
   void *data;

   setInit(setu, set1->match, NULL);

   for (member = listHead(set1); NULL != member; member = listNext(member))
   {
       data = listData(member);

       if (0 != listInsertNext(setu, listTail(setu), data))
       {
           SetDestroy(setu);
           return -1;
       }
   }

   for (member = listHead(set2); NULL != member; member = listNext(member))
   {
       data = listData(member);

       /* 或者if (setIsMember(setu, data)) */
       if (setIsMember(set1, data))
       {
           continue;
       }
       else
       {
            if (0 != listInsertNext(setu, listTail(setu), data ))
            {
                SetDestroy(setu);
                return -1;
            }
       }
   }

   return 0;
}

int setIntersection(Set *seti, const Set *set1, const Set *set2)
{
    ListElmt *member;
    void *data;

    setInit(seti, set1->match, NULL);

    for (member = listHead(set1); NULL != member; member = listNext(member))
    {
        data = listData(member);

        if (setIsMember(set2, data))
        {
            if (0 != listInsertNext(seti, listTail(seti), data))
            {
                SetDestroy(seti);
                return -1;
            }
        }
    }

    return 0;
}

int setDifference(Set *setd, const Set *set1, const Set *set2)
{
    ListElmt *member;
    void *data;

    setInit(setd, set1->match, NULL);

    for (member = listHead(set1); NULL != member; member = listNext(member))
    {
        data = listData(member);

        if (!setIsMember(set2, data))
        {
            if (0 != listInsertNext(setd, listTail(setd), data))
            {
                SetDestroy(setd);
                return -1;
            }
        }
    }

    return 0;
   
}

int setIsMember(Set *set, const void *data)
{
   ListElmt *member;

   for (member = listHead(set); NULL != member; member = listNext(member))
   {
       if (set->match((const void *) data, (const void *) listData(member)))
       {
           return 1;
       }
   }

   return 0;
}

int setIsSubset(const Set *set1, const Set *set2)
{
    ListElmt *member;

    if (listSize(set1) > listSize(set2))
    {
        return 0;
    }

    for (member = listHead(set1); NULL != member; member = listNext(member))
    {
        if (!setIsMember(set2, listData(member)))
        {
            return 0;
        }
    }

    return 1;
}

int setisequal(const Set *set1, const Set *set2)
{
    if (setSize(set1) != setSize(set2))
    {
        return 0;
    }

    return setIsSubset(set1, set2);
}

