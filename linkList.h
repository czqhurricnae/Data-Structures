/**
 *
 * @copyright:
 * @file: linkList.h
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    链表抽象数据类型的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>

/* Define a structure for linked list elements. */
typedef struct ListElmt_
{
   void *data;
   struct ListElmt_ *next;
} ListElmt;

/* Define a structure for linked lists. */
typedef struct List_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
} List;

/* Public Interface */
void listInit(List *list, void (*destroy)(void *data));
void listDestroy(List *list);
int listInsertNext(List *list, ListElmt *element, const void *data);
int listRemoveNext(List *list, ListElmt *element, const void **data);

#define listSize(list) ((list)->size)
#define listHead(list) ((list)->head)
#define listTail(list) ((list)->tail)
#define listIsHead(list, element) ((element) == (list)->head ? 1:0)
#define listIsTail(list, element) ((element) == (list)->tail ? 1:0)
#define listData(element) ((element)->data)
#define listNext(element) ((element)->next)

#endif
