#pragma once
#include "SList.h"
//链表打印
void SLTPrint(SLTNode * phead)
{
  SLTNode * pcur = phead;
  while (pcur)
  {
    printf("%d->",pcur->data);
    //next 存的是下一个节点的地址，而 pcur 就是一个节点
    pcur = pcur->next;//更新 pcur，找到了下一个节点
  }
  printf("NULL");
  printf("\n");
}
