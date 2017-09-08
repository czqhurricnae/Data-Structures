/**
 *
 * @copyright:
 * @file: queue.c
 * @since: 2017-09-08
 * @author: czq | 7160844@qq.com
 * @description:
 *    队列的函数实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-08        1.0             开始创建
 *
 **/

#include <stdlib.h>

#include "linkList.h"
#include "queue.h"

int queueEnqueue(Queue *queue, const void *data)
{
    return listInsertNext(queue, listTail(queue), data);
}

int queueDequeue(Queue *queue, const void **data)
{
    return listRemoveNext(queue, NULL, data);
}
