/**
 *
 * @copyright:
 * @file: stack.h
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    栈抽象数据类型的头文件
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "linkList.h"

/* Implement stacks as linked lists. */
typedef List Stack;

/* Public Interface. */
#define stackInit listInit
#define stackDestroy listDestroy
int stackPush(Stack *stack, const void *data);
int stackPop(Stack *stack, const void **data);
#define stackPeek(stack) (NULL == (stack)->head ? NULL : (stack)->head->data)
#define stackSize listSize

#endif
