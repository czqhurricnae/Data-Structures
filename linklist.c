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
            /* 如果pHead为空指针,说明是第一次插入*/
            pHead = pNewNode;
        }
        else
        {   g_pNodeStru temp = pHead;
            while(NULL != temp->t_pNodeStru)
            {
                temp = temp->t_pNodeStru;
            }
            temp->t_pNodeStru = pNewNode;
            pNewNode->t_pNodeStru = NULL;
        }
    }
    return pHead;
}

g_pNodeStru deleteElement(g_pNodeStru pHead, int number)
{
    if (number == pHead->t_iNumber)
    {
        pHead = pHead->t_pNodeStru;
    }

    /* 必须要判断pHead指向的是否为空指针,否则如果是只有一个
    元素的链表,并且该唯一原始值不是要删除的,此时comparator为空
    comparator->t_pNodeStru是会导致块错误的. */
    else if (NULL != pHead->t_pNodeStru)
    {
        g_pNodeStru preNode = pHead;
        g_pNodeStru comparator = pHead->t_pNodeStru;
        while (NULL != comparator->t_pNodeStru && number != comparator->t_iNumber)
        {
            preNode = comparator;
            comparator = comparator->t_pNodeStru;
        }

        if (number == comparator->t_iNumber)
        {
            preNode->t_pNodeStru = comparator->t_pNodeStru;
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
    if (NULL == pHead)
    {
        printf("这是一个空链表\n");

    }
    else
    {
        /* 下面的写法更简洁 */
        g_pNodeStru temp = pHead;
        while(NULL != temp->t_pNodeStru)
        {
            printf("%d | ", temp->t_iNumber);
            temp= temp->t_pNodeStru;
        }

        /* 如果temp->t_pNodeStru为空说明为最后一个元素*/
        printf("the last one is %d\n", temp->t_iNumber);
    }

    return 0;
}

int main()
{
    int i;
    int deleteNumber;

    /* 创建头节点 */
    g_pNodeStru pHead = NULL;

    /* 初始化随机数生成器 */
    srand(time(NULL));

    for (i = 0; i < 1; ++i)
    {
        /* t_pNewNode = (g_pNodeStru)malloc(sizeof(g_strNodeStru));
        t_pNewNode也必须使用g_pNodeStru进行声明,否则提示错误如下:
        Use of undeclared identifier 't_pNewNode' */

        g_pNodeStru pNewNode = (g_pNodeStru)malloc(sizeof(g_strNodeStru));
        pNewNode->t_pNodeStru = NULL;
        pNewNode->t_iNumber = rand() % 50;
        /* pHead = insertHead(pHead, pNewNode); */
        pHead = insertTail(pHead, pNewNode);
        traverseLinkList(pHead);
    }

    printf("请输入一个你需要删除的数字: \n");
    scanf("%d", &deleteNumber);
    pHead = deleteElement(pHead, deleteNumber);
    traverseLinkList(pHead);
    return 0;
}
