/**
 *
 * @copyright:
 * @file: set.h
 * @since: 2017-09-17
 * @author: czq | 7160844@qq.com
 * @description:
 *    集合抽象数据结构的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-17        1.0             开始创建
 *
 **/

#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "linkList.h"

typedef List Set;

void setInit(Set *set, int (*match)(const void *key1, const void *key2),
void (*destroy)(void *data));
#define SetDestroy listDestroy
int setInsert(Set *set, const void *data);                    
int setRemove(Set *set, const void *data);                    
int setUnion(Set *setu, const Set *set1, const Set *set2);    
int setIntersection(Set *seti, const Set *set1, const Set *set2);
int setDifference(Set *setd, const Set *set1, const Set *set2);
int setIsMember(const Set *set, const void *data);
int setIsSubset(const Set *set1, const Set *set2);
int setIsEqual(const Set *set1, const Set *set2);
#define setSize(set) ((set)->size)

#endif    /*SET_H*/
