/**
 *
 * @copyright:
 * @file: queue.h
 * @since: 2017-09-08
 * @author: czq | 7160844@qq.com
 * @description:
 *    队列抽象数据类型的头文件
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-08        1.0             开始创建
 *
 **/   
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "linkList.h"

/* Implement queue ad linked lists. */
typedef List Queue;

/* Public Interface */
#define queueInit listInit
#define queueDestory listDestroy

int queueEnqueue(Queue *queue, const void *data);
int queueDequeue(Queue *queue, const void **data);

/* 获取队列头元素的信息而并不使头元素出队 */
#define queuePeek(queue) (NULL == (queue)->head ? NULL : (queue)->head->data)
#define queueSize listSize

#endif    /*QUEUE_H*/
