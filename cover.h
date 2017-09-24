/**
 *
 * @copyright:
 * @file: cover.h
 * @since: 2017-09-24
 * @author: czq | 7160844@qq.com
 * @description:
 *    集合覆盖问题的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-24        1.0             开始创建
 *
 **/

#ifndef COVER_H
#define COVER_H

#include "set.h"

/* Defined a structure for subsets identified by a key. */
typedef struct KSet_
{
    void *key;
    Set set;
}KSet;

/* Public interface. */
int cover(Set *members, Set *subsets, Set *covering);

#endif    /*COVER_H*/
