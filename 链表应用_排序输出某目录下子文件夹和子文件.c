# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <malloc.h>
# include <string.h>

typedef struct Node
{
    char *pName;
    struct Node *pNext;
} *pNode, strNode;

pNode insertLocation(pNode pFisrt, pNode newNode)
{
    if (NULL == newNode)
    {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    if (NULL == pFisrt)
    {
        pFisrt = newNode;
        return pFisrt;
    }

    /* 单独判断首节点,这其中包含只有一个首节点和有多个节点时进行迭代比较,comparator不包含
    首节点的情况 ,只要比首节点小就插到前面*/
    if (strcmp(newNode->pName, pFisrt->pName) < 0)
    {
        newNode->pNext = pFisrt;
        pFisrt = newNode;
        return pFisrt;
    }

    pNode preNode = pFisrt;
    pNode comparator = preNode->pNext;

    /* 中断迭代的情况是遇到比新节点大的节点或者comparator已经是尾节点了,再次迭代因为下一轮comparator为NULL,comparator->pNext就会出现错误 */
    while(strcmp(newNode->pName, comparator->pName) > 0 && NULL != comparator ->pNext)
    {
        preNode = comparator;
        comparator = comparator->pNext;
    }

    if (strcmp(newNode->pName, comparator->pName) < 0)
    {
        preNode->pNext = newNode;
        newNode->pNext = comparator;
    }
    else
    {
        comparator->pNext= newNode;
    }

    return pFisrt;
}

int traverseLinkList(pNode pFirst)
{
    if (NULL == pFirst)
    {
        printf("这是一个空链表\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        pNode temp = pFirst;
        while(NULL != temp->pNext)
        {
            printf("%s\n", temp->pName);
            temp = temp->pNext;
        }
        printf("%s\n", temp->pName);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    DIR *directory = opendir(argv[1]);
    struct dirent *pDirectoryEntry = NULL;
    pNode pFirst= NULL;

    while(NULL != (pDirectoryEntry = readdir(directory)))
    {
      if ('.' == pDirectoryEntry->d_name[0] || '..' == pDirectoryEntry->d_name[0])
        {
            continue;
        }
        printf("未排序: %s\n", pDirectoryEntry->d_name);
        pNode newNode = (pNode)malloc(sizeof(strNode));
        /* 不必写成 int len = strlen(pDirectoryEntry->d_name[0]); */
        int len = strlen(pDirectoryEntry->d_name);
        newNode->pName = malloc(len + 1);
        memset(newNode->pName, '\0', len+1);
        strncpy(newNode->pName, pDirectoryEntry->d_name, len);
        newNode->pNext = NULL;
        pFirst= insertLocation(pFirst, newNode);
    }

    traverseLinkList(pFirst);
    return 0;
}
