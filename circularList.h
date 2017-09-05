/**
 *
 * @copyright:
 * @file: circularList.h
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    循环链表抽象数据类型的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <stdlib.h>

typedef struct CListElmt_
{
    void *data;
    struct CListElmt_ *next;
} CListElmt;

typedef struct CList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    CListElmt *head;
} CList;

/* Public Interface. */
void cListInit(CList *list, void (*destroy)(void *data));
void cListDestroy(CList *list);
int cListInsertNext(CList *list, CListElmt *element, const void *data);
int cListRemoveNext(CList *list, CListElmt *element, const void **data);
#define cListSize(list) ((list)->size)
#define cListHead(list) ((list)->head)
#define cListData(element) ((element)->data)
#define cListNext(element) ((element)->next)

#endif
