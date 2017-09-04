#include <stdlib.h>
#include <string.h>

#include "doublyLinkList.h"

/**
 * Function: dListInit
 * Description:
 *    destroy参数提供了一种释放动态分配空间的方法, 对于双向链表, 如果其中不包含不需要手动释放
 *    空间的数据, destroy参数应该设置为NULL
 * Calls:
 * Called By:
 * Input:
 * Output:
 * Return:
 * Table Accessed:
 * Table Updated:
 * Others:
 *    复杂度O(1)
 **/
void dListInit(DList *list, void(*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

/**
 * Function: dListDestory
 * Description:
 *    该函数将移除双向链表中的所有元素, 如果传给dListInit的参数destroy不为NULL, 则调用destroy
 *    所指定的函数, 对链表中每个移除的元素数据施行资源回收操作.
 * Calls:
 * Called By:
 * Input:
 * Output:
 * Return:
 * Table Accessed:
 * Table Updated:
 * Others:
 **/
void dListDestory(DList *list)
{
  void *data;

  while (dListSize(list) > 0)
  {
      if (1 != dListRemove(list, dListTail(list), (const void **)&data)
          && NULL != list->destroy )
      {
          /* Call a user-defined function to free dynamically allocated data. */
         list->destroy(data); 
      }
  }
  /* No operation are allowed now, but clear the structure as a precaution. */
  /* 对结构体DList *list进行清零 */
  memset(list, 0, sizeof(DList));
}

int dListInsertNext(DList *list, DListElmt *element, const void *data)
{
    DListElmt *newElement;

    if (NULL == (newElement = (DListElmt *)malloc(sizeof(DListElmt))))
    {
        return -1;
    }

    if (NULL == element && 0 == dListSize(list))
    {
        return -1;
    }

    newElement->data = (void *)data;

    if (0 == dListSize(list))
    {
        list->head = newElement;
        list->head->previous = NULL;
        list->head->next = NULL;

        /* 改成list->tail = list->head; 是不是更好呢, 这样也同时指明了list->tail的next和 */
        /* previous值 */
        list->tail = newElement;
    }
    else
    {
        newElement->next = element->next;
        newElement->previous = element;

        /* 不能直接写element->next->previous = newElement, 因为有可能NULL == element->next */
        if (NULL == element->next)
        {
            list->tail = newElement;
            /* 此时不必再写明list->tail = NULL, 因为前面已经写明newElement = element->next */
            /* 而此时element->next为NULL. */
        }
        else
        {
           element->next->previous = newElement; 
        }

        element->next = newElement;
    }

    /* dListSize(list)++; */
    list->size++;

    return 0;
}

int dListInsertPrevious(DList *list, DListElmt *element, const void *data)
{
    DListElmt *newElement;

    if (NULL == (newElement = (DListElmt *)malloc(sizeof(DListElmt))))
    {
       return -1; 
    }

    if (NULL == element && 0 == dListSize(list))
    {
        return -1;
    }

    newElement->data = (void *)data;

    if (0 == dListSize(list))
    {
        list->head = newElement;
        list->head->next = NULL;
        list->head->previous = NULL;
        list->tail = newElement;
    }
    else
    {
       newElement->next = element;
       newElement->previous = element->previous;

       if (NULL == element->previous)
       {
           list->head = newElement;
       }
       else
       {
           element->previous->next = newElement;
       }

       element->previous = newElement;
    }

    list->size++;

    return 0;
}

int dListRemoveNext(DList *list, DListElmt *element, const void **data)
{
    if (NULL == element || 0 == dListSize(list))
    {
        return -1;
    }

    *data = element->data;

    /* 相当于判断了element->previous是否为NULL, 如果不进行此判断element->previous->next会 */
    /* 导致错误. */
    if (list->head == element)
    {
        list->head = element->next;

        /* 说明element->next为NULL, 则不能写明element->next->previous. */
        if (NULL == list->head)
        {
            list->tail = NULL;
        }
        else
        {
            element->next->previous = NULL;
        }
    }   
    else
    {
        element->previous->next = element->next;

        /* 不能直接写明element->next->previous = element->previous; 因为有可能element->next */
        /* 为NULL. */
        if (NULL == element->next)
        {
            list->tail = element->previous;
        }
        else
        {
            element->next->previous = element->previous;
        }
    }

    list->size--;

    free(element);

    return 0;
}
