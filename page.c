/**
 *
 * @copyright:
 * @file: page.c
 * @since: 2017-09-05
 * @author: czq | 7160844@qq.com
 * @description:
 *    第二次机会页面置换算法的实现 
 * @usage:
 * @others:
 * @TODO:
 * @Revision History:
 * Date            Rel Ver.        Notes
 * 2017-09-05        1.0             开始创建
 *
 **/

#include "page.h"
#include "circularList.h"

int replacePage(CListElmt **current)
{
    while (0 != ((PAGE *)(*current)->data)->reference)
    {
       ((PAGE *)(*current)->data)->reference = 0; 
       *current = cListNext(*current);
    }

    return ((PAGE *)(*current)->data)->number;
}
