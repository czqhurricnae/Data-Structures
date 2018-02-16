/**
 *
 * @copyright:
 * @file: bitree_traverse.c
 * @since: 2018-02-15
 * @author: czq | 7160844@qq.com
 * @description:
 *     遍历二叉树的实现函数 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2018-02-15        1.0             开始创建
 *
 **/

#include "linkList.h"
#include "bitree.h"
#include "bitree_traverse.h"

int preorder(BiTreeNode *node, List *list)
{
    if (!bitreeIsEob(node))
    {
       if (0 != listInsertNext(list, listTail(list), (const void *)bitreeData(node)))
       {
           return -1;
       } 

       if (!bitreeIsEob(bitreeLeft(node)))
       {
           if (0 != preorder(bitreeLeft(node), list))
            {
                return -1;
            }
       }

       if (!bitreeIsEob(bitreeRight(node)))
       {
           if (0 != preorder(bitreeRight(node), list))
           {
               return -1;
           }
       }
    }

    return 0;
}

int inorder(BiTreeNode *node, List *list)
{
    if (!bitreeIsEob(node))
    {
        if (!bitreeIsEob(bitreeLeft(node)))
        {
            if (0 != inorder(bitreeLeft(node), list))
            {
                return -1;
            }
        }

        if (0 != listInsertNext(list, listTail(list), (const void *)bitreeData(node)))
        {
            return -1;
        } 

        if (!bitreeIsEob(bitreeRight(node)))
        {
            if (0 != inorder(bitreeRight(node), list))
            {
                return -1;
            }
        }
    }

    return 0;
}

int postorder(BiTreeNode *node, List *list)
{
    if (!bitreeIsEob(node))
    {
        if (!bitreeIsEob(bitreeLeft(node)))
        {
            if (0 != postorder(bitreeLeft(node), list))
            {
                return -1;
            }
        }

        if (!bitreeIsEob(bitreeRight(node)))
        {
            if (0 != postorder(bitreeRight(node), list))
            {
                return -1;
            }
        }

        if (0 != listInsertNext(list, listTail(list), (const void *)bitreeData(node)))
        {
            return -1;
        } 
    }

    return 0;
}
