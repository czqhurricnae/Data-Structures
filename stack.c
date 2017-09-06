/**
 *
 * @copyright:
 * @file: stack.c
 * @since: 2017-09-06
 * @author: czq | 7160844@qq.com
 * @description:
 *    栈的函数实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-06        1.0             开始创建
 *
 **/

#include <stdlib.h>

#include "linkList.h"
#include "stack.h"

int stackPush(Stack *stack, const void *data)
{
    return listInsertNext(stack, NULL, data);
}

int stackPop(Stack *stack, const void **data)
{
   return listRemoveNext(stack, NULL, data); 
}
