/**
 *
 * @copyright:
 * @file: bitree.c
 * @since: 2018-02-14
 * @author: czq | 7160844@qq.com
 * @description:
 *     抽象数据类型二叉树的实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2018-02-14        1.0             开始创建
 *
 **/

#include <stdlib.h>
#include <string.h>
#include "bitree.h"

void bitreeInit(BiTree *tree, void (*destroy)(void *data))
{
    tree->size = 0;
    tree->root = NULL;
    tree->destroy = destroy;

    return;
}

void bitreeDestroy(BiTree *tree)
{
    /* Remove all the nodes from the tree. */
    bitreeRemoveLeft(tree, NULL); 

    /* No operations are allowed now, but clear the structure as a precaution. */
    memset(tree, 0, sizeof(BiTree));

    return;
}

int bitreeInsertLeft(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *newNode, **position;

    if (NULL == node)
    {
        /* Allow insertion at the root only in an empty tree. */
        if (0 != bitreeSize(tree))
        {
            return -1; 
        } 

        position = &tree->root;
    } 
    else
    {
        /* Normally allow insertion only at the end of a branch. */
        if (NULL != bitreeLeft(node))
        {
            return -1;
        }

        position = &(node->left);
    }

    if (NULL == (newNode = (BiTreeNode *)malloc(sizeof(BiTreeNode))))
    {
        return -1; 
    }
    else
    {
        newNode->data = (void *)data;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    *position = newNode;
    tree->size++;

    return 0;
}

int bitreeInsRight(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *newNode, **position;

    if (NULL == node)
    {
        if (0 == bitreeSize(tree))
        {
            return -1;
        };

        position = &tree->root;
    }
    else
    {
        if (NULL != bitreeRight(node))
        {
            return -1;
        }

        position = &(node->right);
    }

    if (NULL == (newNode=(BiTreeNode *)malloc(sizeof(BiTreeNode))))
    {
        return -1;
    }

    newNode->data = (void *)data;
    newNode->left = NULL;
    newNode->right = NULL;

    *position = newNode;
    tree->size++;

    return 0;
}

void bitreeRemoveLeft(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (0 == bitreeSize(tree))
    {
        return;
    }

    if (NULL == node)
    {
        position = &tree->root;
    }
    else
    {
        position = &node->left;
    }

    if (NULL != *position)
    {
        bitreeRemoveLeft(tree, *position);
        bitreeRemoveRight(tree, *position);

        if (NULL != tree->destroy)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size--;
    }
    return;
}

void bitreeRemoveRight(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (0 == bitreeSize(tree))
    {
        return;
    }

    if (NULL == node)
    {
        position = &tree->root;
    }
    else
    {
        position = &node->right;
    }

    if (NULL != *position)
    {
        bitreeRemoveLeft(tree, *position);
        bitreeRemoveRight(tree, *position);

        if (NULL != tree->destroy)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size--;
    }
    return;
}

int bitreeMerge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
   bitreeInit(merge, left->destroy); 

   if (0 != bitreeInsertLeft(merge, NULL, data))
   {
       bitreeDestroy(merge);
       return -1;
   }

   bitreeRoot(merge)->left = bitreeRoot(left);
   bitreeRoot(merge)->right = bitreeRoot(right);
   merge->size = merge->size + bitreeSize(left)+ bitreeSize(right);

   /* Do not let the original trees access the merged nodes. */
   left->root = NULL;
   left->size = 0;
   right->root = NULL;
   right->size = 0;

   return 0;
}
