/**
 *
 * @copyright:
 * @file: events.h
 * @since: 2017-09-08
 * @author: czq | 7160844@qq.com
 * @description:
 *    队列的应用: 消息队列的头文件-算法精解-C语言实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-08        1.0             开始创建
 *
 **/

#ifndef EVENTS_H
#define EVENTS_H
#include "queue.h"
#include "event.h"

int receiveEvent(Queue *events, Event *event);
int processEvent(Queue *events, int (*dispatch)(Event *event));

#endif    /*EVENTS_H*/
