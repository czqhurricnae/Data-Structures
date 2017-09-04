/**
 *
 * @copyright:
 * @file: doublyLinkList.h
 * @since: 2017-09-01
 * @author: czq | 7160844@qq.com
 * @description:
 *     双向链表抽象数据类型的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-01        1.0             开始创建
 *
 **/
#ifndef DOUBLYLINKLIST_H
#define DOUBLYLINKLIST_H

#include <stdlib.h>

typedef struct DListElmt_
{
    void *data;
    struct DListElmt_ *previous;
    struct DListElmt_ *next;
} DListElmt;

typedef struct DList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DListElmt *tail;
} DList;

/* Public Interface */
void dListInit(DList *list, void (*destroy)(void *data));
void dListDestory(DList *list);
int dListInsertNext(DList *list, DListElmt *element, const void *data);
int dListInsertPrevious(DList *list, DListElmt *element, const void *data);
int dListRemove(DList *list, DListElmt *element, const void **data);
#define dListSize(list) ((list)->size)
#define dListHead(list) ((list)->head)
#define dListTail(list) ((list)->tail)
#define dListIsHead(element) (NULL == (element)->previous ？1 : 0)
#define dListIsTail(element) (NULL == (element)->next ？1 : 0)
#define dListData(element) ((element)->data)
#define dListNext(element) ((element)->next)
#define dListPrevious(element) ((element)->previous)

#endif
