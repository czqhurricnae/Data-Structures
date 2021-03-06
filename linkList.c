/**
 *
 * @copyright:
 * @file: linkList.c
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    链表的函数实现 
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
#include "linkList.h"

/**
 * Function: listInit
 * Description:
 * Calls:
 * Called By:
 * Input:
 * Output:
 * Return:
 * Table Accessed:
 * Table Updated:
 * Others:
 **/
void listInit(List *list, void (destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return ;
}

/**
 * Function: listDestroy
 * Description:
 *    调用listDestroy后任何其他的操作都不允许执行, 除非再次调用listInit.listDestroy将链表
 *    中所有的元素都移除, 如果传给listInit的参数destroy不为NULL, 则移除链表中每个元素时都调
 *    用该函数一次.
 * Calls:
 * Called By:
 * Input:
 * Output:
 * Return:
 * Table Accessed:
 * Table Updated:
 * Others:
 *    复杂度0(n)
 **/
void listDestroy(List *list)
{
    void *data;

    while (listSize(list) > 0)
    {
        if (0 == listRemoveNext(list, NULL, (const void **)&data)
            && NULL != list->destroy)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            list->destroy(data);
        }

    }

    /* No operations are allowed now, but clear the structure as a precaution. */
    memset(list, 0, sizeof(List));

    return ;
}

/**
 * Function: listInsertNext
 * Description:
 *    如果element设置为NULL, 则新元素插入链表头部
 * Calls:
 * Called By:
 * Input:
 * Output:
 * Return:
 *    如果插入元素成功则返回0, 否则返回-1
 * Table Accessed:
 * Table Updated:
 * Others:
 *    复杂度0(1)
 **/
int listInsertNext(List *list, ListElmt *element, const void *data)
{
   ListElmt *newElement;

   if (NULL != (newElement = (ListElmt *)malloc(sizeof(ListElmt))))
       return -1;

   newElement->data = (void *)data;

   if (NULL == element)
   {
       /* 当插入的元素位于链表末尾时, 必须更新链表数据结构的tail成员使其指向新的节点 */
      if (0 == listSize(list))
      {
          list->tail = newElement;
      }

      newElement->next = list->head;
      list->head = newElement;
   }
   else
   {
       if (NULL == element->next)
       {
           list->tail = newElement;
       }

       newElement->next = element->next;
       element->next = newElement;
   }

   list->size++;

   return 0;
}

/**
 * Function:
 * Description:
 *    如果element设置为NULL, 则移除链表头部
 * Calls:
 * Called By:
 * Input:
 * Output:
 *    data指向已移除元素中存储的数据
 * Return:
 *    如果移除元素成功则返回0, 否则返回-1
 * Table Accessed:
 * Table Updated:
 * Others:
 *    复杂度0(1)
 **/
int listRemoveNext(List *list, ListElmt *element, const void **data)
{
    ListElmt *oldElement;

    /* Do not allow remove from an empty list. */
    if (0 == listSize(list))
    {
        return -1;
    }
    if (NULL == element)
    {
        *data = list->head->data;
        oldElement = list->head;

        /* 当1 == listSize(list)时, list->head->next = NULL, 所以当移除头元素后不必重复 */
        /* 写明list->head = NULL */
        list->head = list->head->next;
        /* 当移除的目标节点是链表的尾部节点时, 更新链表数据结构中的tail成员, 使其指向新的尾节点 */
        if (1 == listSize(list))
        {
            list->tail = NULL;
        }
    }
    else
    {
        if (NULL == element->next)
            return -1;

        *data = element->next->data;
        oldElement = element->next;
        element->next = element->next->next;

        if (NULL == element->next)
        {
            list->tail = element;
        }
    }

    free(oldElement);

    list->size--;

    return 0;
}
