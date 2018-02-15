/**
 *
 * @copyright:
 * @file: bitree.h
 * @since: 2018-02-14
 * @author: czq | 7160844@qq.com
 * @description:
 *     二叉树抽象数据类型的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2018-02-14        1.0             开始创建
 *
 **/

#ifndef BITREE_H
#define BITREE_H
#include <stdlib.h>

/* Define a structure for binary tree nodes. */
typedef struct BiTreeNode_
{
    void *data;
    struct BiTreeNode_ *left;
    struct BiTreeNode_ *right;
} BiTreeNode;

/* Define a structure for binary trees. */
typedef struct BiTree_
{
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    BiTreeNode *root;
} BiTree;

/* Public Interface */
void bitreeInit(BiTree *tree, void (*destroy)(void *data));
void bitreeDestroy(BiTree *tree);
int bitreeInsertLeft(BiTree *tree, BiTreeNode *node, const void *data);
int bitreeInsertRight(BiTree *tree, BiTreeNode *node, const void *data);
void bitreeRemoveLeft(BiTree *tree, BiTreeNode *node);
void bitreeRemoveRight(BiTree *tree, BiTreeNode *node);
int bitreeMerge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

#define bitreeSize(tree) ((tree)->size)
#define bitreeRoot(tree) ((tree)->root)
#define bitreeIsEob(node) ((node) == NULL)
#define bitreeIsLeaf(node) ((node)->left == NULL && (node)->right == NULL)
#define bitreeData(node) ((node)->data)
#define bitreeLeft(node) ((node)->left)
#define bitreeRight(node) ((node)->right)

#endif    /*BITREE_H*/
