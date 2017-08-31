/**
 *
 * @copyright:
 * @file: linkList.c
 * @since: 2017-06-21
 * @author: czq | 7160844@qq.com
 * @description:
 *     没有设置头节点的链表
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-06-21        1.0             开始创建
 *
 **/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct NODE
{
    int iData;
    struct NODE *pNext;
} *pNode, strNode;

pNode insertFirst(pNode pFirst, pNode pNewNode)
{
    if (NULL == pNewNode)
    {
        printf("内存分配失败, 程序终止\n");
        exit(-1);
    }

    pNewNode->pNext= pFirst;
    pFirst = pNewNode;

    return pFirst;
}

pNode appendTail(pNode pFirst, pNode pNewNode)
{
    if (NULL == pNewNode)
    {
        printf("内存分配失败, 程序终止\n");
        exit(-1);
    }
    else
    {
        if (NULL == pFirst)
        {
            /* 如果pFirst为空指针,说明是第一次插入*/
            pFirst = pNewNode;
        }
        else
        {
            pNode temp = pFirst;
            while(NULL != temp->pNext)
            {
                temp = temp->pNext;
            }
            temp->pNext = pNewNode;
            pNewNode->pNext = NULL;
        }
    }

    return pFirst;
}

pNode deleteElement(pNode pFirst, int data)
{
    if (NULL == pFirst)
    {
      printf("这是一个空链表\n");
      exit(0);
    }
    else if (data == pFirst->iData)
    {
        pFirst = pFirst->pNext;
    }

    /* 必须要判断pNode comparator = pFirst->pNext指向的是否为空指针,否则如果是只有一个元素
    的链表,并且该唯一原始值不是要删除的,此时comparator为空,comparator->pNext是会导致块错误的. */
    else if (NULL != pFirst->pNext)
    {
        pNode preNode = pFirst;
        pNode comparator = preNode->pNext;
        while (NULL != comparator->pNext && data != comparator->iData)
        {
            preNode = comparator;
            comparator = preNode->pNext;
        }

        if (data == comparator->iData)
        {
            preNode->pNext = comparator->pNext;
        }
    }

    return pFirst;
}

int traverseLinkList(pNode pFirst)
{
    /* 如果是只有一个元素的链表则无法正确遍历 */
    /* if (NULL != pFirst->pNext)
    {
        printf("%d\n", pFirst->iData);
        pFirst = pHead->pNext;
        traverseLinkList(pFirst);
    }
    else
    {
        exit(0);
    } */

    if (NULL == pFirst)
    {
        printf("这是一个空链表\n");
    }
    else
    {
        /* 下面的写法更简洁 */
        pNode temp = pFirst;
        while(NULL != temp->pNext)
        {
            printf("%d | ", temp->iData);
            temp= temp->pNext;
        }

        /* 如果temp->pNext为NULL说明为最后一个元素*/
        printf("the last one is %d\n", temp->iData);
    }

    return 0;
}

pNode createList(void)
{
    int length;
    int data;

    printf("请输入你需要的节点个数: ");
    scanf("%d", &length);

    /* 创建首节点 */
    pNode pFirst = NULL;

    /* 初始化随机数生成器 */
    srand(time(NULL));

    for (int i = 0; i < length; ++i)
    {
        printf("请输入第%d个节点的值: ", i+1);
        scanf("%d", &data);

        /* pNewNode = (pNode)malloc(sizeof(strNode));pNewNode也必须使用pNode进行声明,
           否则提示错误如下:Use of undeclared identifier 'pNewNode' */
        pNode pNewNode = (pNode)malloc(sizeof(strNode));
        pNewNode->pNext = NULL;

        /* pNewNode->iData = rand() % 50; */
        pNewNode->iData = data;

        pFirst = insertFirst(pFirst, pNewNode);
        /* pFirst = appendTail(pHead, pNewNode); */
    }

    return pFirst;
}

int main()
{
    int deleteData;
    pNode pFirst = createList();
    traverseLinkList(pFirst);
    printf("请输入一个你需要删除的数字: ");
    scanf("%d", &deleteData);
    pFirst = deleteElement(pFirst, deleteData);
    traverseLinkList(pFirst);

    return 0;
}
