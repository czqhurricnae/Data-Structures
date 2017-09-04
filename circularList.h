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
    CListElmt head;
} CList;

void cListInit(CList *list, void (*destroy)(void *data));
void cListDestroy(CList *list);
int cListInsertNext(CList *list, CListElmt *element, const void *data);
int cListRemoveNext(CList *list, CListElmt *element, const void **data);
#define cListSize(list) ((list)->size)
#define cListHead(list) ((list)->head)
#define cListData(element) ((element)->data)
#define cListNext(element) ((element)->next)

#endif
