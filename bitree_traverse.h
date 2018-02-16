/**
 *
 * @copyright:
 * @file: bitree_traverse.h
 * @since: 2018-02-16
 * @author: czq | 7160844@qq.com
 * @description:
 *     遍历二叉树的头文件 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2018-02-16        1.0             开始创建
 *
 **/

#ifndef BITREE_TRAVERSE_H
#define BITREE_TRAVERSE_H

#include "linkList.h"
#include "bitree.h"

/* Public Interface */
int preorder(const BiTreeNode *node, List *list);
int inorder(const BiTreeNode *node, List *list);
int postorder(const BiTreeNode *node, List *list);

#endif    /*BITREE_TRAVERSE_H*/
