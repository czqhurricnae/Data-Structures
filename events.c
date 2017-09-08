/**
 *
 * @copyright:
 * @file: events.c
 * @since: 2017-09-08
 * @author: czq | 7160844@qq.com
 * @description:
 *    队列的应用: 消息队列的函数实现-算法精解-C语言实现
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-08        1.0             开始创建
 *
 **/
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "event.h"
#include "events.h"

int receiveEvent(Queue *events, Event *event)
{
    Event *newEvent;

    if (NULL == (newEvent = (Event *)malloc(sizeof(Event))))
    {
        return -1;
    }

    memcpy(newEvent, event, sizeof(Event));

    if (0 != queueEnqueue(events, newEvent))
    {
        return -1;
    }

    return 0;
}

int processEvent(Queue *events, int (*dispatch)(Event *event))
{
    Event *event;

    if (0 == queueSize(events))
    {
        return -1;
    }

    if (0 != queueDequeue(events, (const void **)&event))
    {
        return -1;
    }
    else
    {
        dispatch(event);
        free(event);
    }

    return 0;
}
