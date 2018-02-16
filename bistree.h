/**
 *
 * @copyright:
 * @file: bistree.h
 * @since: 2018-02-16
 * @author: czq | 7160844@qq.com
 * @description:
 *     二叉搜索树抽象数据类型的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2018-02-16        1.0             开始创建
 *
 **/

#ifndef BISTREE_H
#define BISTREE_H

#include "bitree.h"

/* Define balance factors for AVL trees. */
#define AVL_LFT_HEAVY 1
#define AVL_BALANCED  0
#define AVL_RGT_HEAVY -1

/* Define a structure for nodes in AVL trees. */
typedef struct AvlNode_
{
    void * data;
    int hidden;
    int factor;
} AvlNode;

/* Implement binary search trees as binary trees. */
typedef BiTree BisTree;

/* Public Interface */
void bistreeInit(BisTree *tree, int (*compare)(const void *key1, const void *key2),
    void (*destroy)(void *data));
void bistreeDestroy(BisTree *tree);
int bistreeInsert(BisTree *tree, const void *data);
int bistreeRemove(BisTree *tree, const void *data);
int bistreeLookup(BisTree *tree, void **data);
#define bistreeSize(tree) ((tree)->size)

#endif    /*BISTREE_H*/
