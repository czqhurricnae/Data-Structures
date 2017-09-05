/**
 *
 * @copyright:
 * @file: page.h
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *     第二次机会页面置换算法的头文件
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#ifndef PAGE_H
#define PAGE_H

#include "circularList.h"

typedef struct PAGE_
{
    int number;
    int reference;
}PAGE;

int replacePage(CListElmt **current);

#endif
