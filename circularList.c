/**
 *
 * @copyright:
 * @file: circularList.c
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    单向循环链表的函数实现
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#include <stdlib.h>
#include <string.h>

#include "circularList.h"

void cListInit(CList *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;
}

void cListDestroy(CList *list)
{
   void *data; 

   while (0 < cListSize(list))
   {
       if (0 == cListRemoveNext(list, NULL, (const void **)&data)
           && NULL != list->destroy)
       {
           list->destroy(data); 
       }
   }

   memset(list, 0, sizeof(CList));

   return;
}

int cListInsertNext(CList *list, CListElmt *element, const void *data)
{
    CListElmt *newElement;

    if (NULL == (newElement = (CListElmt *)malloc(sizeof(CListElmt))))
    {
        return -1;
    }

    newElement->data = (void *)data;

    if (0 == cListSize(list))
    {
        newElement->next = newElement;
        list->head = newElement;
    }
    else
    {
        newElement->next = element->next;
        element->next = newElement;
    }

    list->size++;

    return 0;
}

int cListRemoveNext(CList *list, CListElmt *element, const void **data)
{
    CListElmt *oldElement;

    if (0 == cListSize(list))
    {
        return -1;
    }

    *data = element->next->data;

    if (element == element->next)
    {
        list->head = NULL;
        oldElement = element;
    }  
    else
    {
       oldElement = element->next;
       element->next = element->next->next;

       if (oldElement == cListHead(list))
       {
           list->head = oldElement->next;
       }
    }

    free(oldElement);

    list->size--;

    return 0;
}
