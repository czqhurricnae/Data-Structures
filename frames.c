/**
 *
 * @copyright:
 * @file: frames.c
 * @since: 2017-09-01
 * @author: czq | 7160844@qq.com
 * @description:
 *     frames
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-01        1.0             开始创建
 *
 **/
#include <stdlib.h>

#include "linkList.h"
#include "frames.h"

int allocateFrame(List *frame)
{
    int frameNumber, *data;

    if (0 == listSize(frame))
    {
        return -1;
    }
    else
    {
       if (0 != listRemoveNext(frame, NULL, (const void **)&data))
       {
           return -1;
       }
       else
       {
           frameNumber = *data;
           free(data);
       }
    }

    return frameNumber;
}

int freeFrame(List *frame, int frameNumber)
{
    int *data;
    if (NULL == (data = (int *)malloc(sizeof(int))))
    {
        return -1;
    }
    else
    {
        data = &frameNumber;
        if (0 != listInsertNext(frame, NULL, (const void *)data))
        {
            return -1;
        }
        else
        {
            free(data);
        }
    }

    return 0;
}
