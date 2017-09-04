#include <stdlib.h>

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
void dListInit(dList *list, void(*destroy)(void *data))
{
    
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
void dListDestory(dList *list)
{
    
}

int dListInsertNext(dList *list, dListElmt *element, const void *data)
{
    
}

int dListRemoveNext(dList *list, dListElmt *element, const void **data)
{
    
}
