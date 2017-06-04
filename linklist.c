# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct NODE_STRU
{
    int t_iNumber;
    struct NODE_STRU *t_pNodeStru;
} *g_pNodeStru, g_strNodeStru;

g_pNodeStru insertHead(g_pNodeStru pHead, g_pNodeStru pNewNode)
{
    if (NULL == pNewNode)
    {
        exit(0);
    }

    pNewNode->t_pNodeStru = pHead;
    pHead = pNewNode;

    return pHead;
}

g_pNodeStru insertTail(g_pNodeStru pHead, g_pNodeStru pNewNode)
{
    if (NULL == pNewNode)
    {
        exit(0);
    }
    else
    {
        if (NULL == pHead)
        {
            pHead = pNewNode;
        }
        else
        {   g_pNodeStru temp = pHead;
            while(temp->t_pNodeStru)
            {
                temp = temp->t_pNodeStru;
            }
            temp->t_pNodeStru = pNewNode;
            pNewNode->t_pNodeStru = NULL;
        }
    }
    return pHead;
}

int traverseLinkList(g_pNodeStru pHead)
{
    /* if (NULL != pHead->t_pNodeStru)
    {
        printf("%d\n", pHead->t_iNumber);
        pHead = pHead->t_pNodeStru;
        traverseLinkList(pHead);
    }
    else
    {
        exit(0);
    } */

    /* 下面的写法更简洁 */
    g_pNodeStru temp = pHead;
    while(NULL != temp->t_pNodeStru)
    {
        printf("%d | ", temp->t_iNumber);
        temp= temp->t_pNodeStru;
    }

    /* 这句不可以省略 */
    printf("%d\n", temp->t_iNumber);
    return 0;
}

int main()
{
    int i;

    /* 创建头节点 */
    g_pNodeStru pHead = NULL;

    /* 初始化随机数生成器 */
    srand(time(NULL));

    for (i = 0; i < 10; ++i)
    {
        /* t_pNewNode = (g_pNodeStru)malloc(sizeof(g_strNodeStru));
        t_pNewNode也必须使用g_pNodeStru进行声明,否则提示错误如下:
        Use of undeclared identifier 't_pNewNode' */

        g_pNodeStru pNewNode = (g_pNodeStru)malloc(sizeof(g_strNodeStru));
        pNewNode->t_iNumber = rand() % 50;
        /* pHead = insertHead(pHead, pNewNode); */
        pHead = insertTail(pHead, pNewNode);
        traverseLinkList(pHead);
    }


    return 0;
}
