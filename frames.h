/**
 *
 * @copyright:
 * @file: frames.h
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    链表的应用: 页帧管理函数实现的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#ifndef FRAMES_H
#define FRAMES_H

#include "linkList.h"

int allocateFrame(List *frame);
int freeFrame(List *frame, int frameNumber);

#endif
