# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <malloc.h>
# include <string.h>

typedef struct NodeStru
{
    char *t_pName;
    struct NodeStru *t_pNodeStru;
} *g_pNodeStru, g_strNodeStru;

g_pNodeStru insert_location(g_pNodeStru pHead, g_pNodeStru newNode)
{
    if (NULL == newNode)
    {
        exit(EXIT_FAILURE);
    }

    if (NULL == pHead)
    {
        pHead = newNode;
        return pHead;
    }

    /* 单独判断首节点,这其中包含只有一个首节点和有多个节点时进行迭代比较,comparator不包含
    首节点的情况 ,只要比首节点小就插到前面*/
    if (strcmp(newNode->t_pName, pHead->t_pName) < 0)
    {
        newNode->t_pNodeStru = pHead;
        pHead = newNode;
        return pHead;
    }

    /* [>既然新节点没有比首节点小,且只有一个节点,就将新节点插到首节点后面<]
    if (NULL == pHead->t_pNodeStru)
    {
        pHead->t_pNodeStru = newNode;
        return pHead;
    }

    g_pNodeStru preNode = pHead;
    g_pNodeStru comparator = preNode->t_pNodeStru;

    [>中断迭代的情况是遇到比新节点大的节点或者comparator已经是尾节点了,再次迭代因为
    下一轮comparator为NULL,comparator->t_pNodeStru就会出现错误<]
    while(strcmp(newNode->t_pName, comparator->t_pName) > 0 && NULL != comparator ->t_pNodeStru)
    {
        preNode = comparator;
        comparator = comparator->t_pNodeStru;
    }
    if (strcmp(newNode->t_pName, comparator->t_pName) < 0)
    {
        preNode->t_pNodeStru = newNode;
        newNode->t_pNodeStru = comparator;
    }
    else
    {
        comparator->t_pNodeStru= newNode;
    }
     */

    /* 上面的写法是比较到comparator为次未节点的情况,下面的写法是比较到comparator为NULL,
    为什么comparator能迭代到尾节点NULL,说明上一轮比较新节点和次尾节点即旧的comparator
    还是新节点大 */
    while(NULL != comparator->t_pNodeStru)
    {
        if (strcmp(newNode->t_pName, comparator->t_pName) > 0)
        {
            preNode = comparator;
            comparator = comparator->t_pNodeStru;
        }
        else
            break;
    }
    /* 如果是因为comparator为NULL而终止的迭代,那么因为新节点还是比次尾节点大,并且
    comparator指向NULL,使用下面的语句还是可以让新节点成为新的尾节点的. */
    preNode->t_pNodeStru = newNode;
    newNode->t_pNodeStru = comparator;
    return pHead;
}

int traverse_linkList(g_pNodeStru pHead)
{
    if (NULL == pHead->t_pNodeStru)
    {
        exit(EXIT_FAILURE);
    }

    g_pNodeStru temp = pHead;
    printf("%s\n", temp->t_pName);

    if (NULL !=  temp->t_pNodeStru)
    {
        g_pNodeStru preNode = temp;
        g_pNodeStru comparator = preNode->t_pNodeStru;
        while (NULL != comparator->t_pNodeStru)
        {
            printf("%s\n", comparator->t_pName);
            preNode = comparator;
            comparator = comparator->t_pNodeStru;
        }
    printf("%s\n", comparator->t_pName);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    DIR *directory = opendir(argv[1]);
    struct dirent *p_directoryEntry = NULL;
    g_pNodeStru pHead = NULL;
    while(NULL != (p_directoryEntry = readdir(directory)))
    {
        if ('.' == p_directoryEntry->d_name[0] || '..' == p_directoryEntry->d_name[0])
        {
            continue;
        }
        printf("未排序: %s\n", p_directoryEntry->d_name);
        g_pNodeStru newNode = malloc(sizeof(g_pNodeStru));
        /* 不必写成 int len = strlen(p_directoryEntry->d_name[0]); */
        int len = strlen(p_directoryEntry->d_name);
        newNode->t_pName = malloc(len + 1);
        memset(newNode->t_pName, '\0', len+1);
        strncpy(newNode->t_pName, p_directoryEntry->d_name, len);
        newNode->t_pNodeStru = NULL;
        pHead = insert_location(pHead, newNode);
    }

    traverse_linkList(pHead);
    return 0;
}
