#pragma once
#include "SList.h"
//测试
void SLTTest01()
{
  //定义节点，并为节点开辟空间
  SLTNode * node1 = (SLTNode *)malloc(sizeof(SLTNode));
  node1->data = 1;
  SLTNode * node2 = (SLTNode *)malloc(sizeof(SLTNode));
  node2->data = 2;
  SLTNode * node3 = (SLTNode *)malloc(sizeof(SLTNode));
  node3->data = 3;
  SLTNode * node4 = (SLTNode *)malloc(sizeof(SLTNode));
  node4->data = 4;
  //将节点中的指针指向下一个节点
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = NULL;
  SLTNode *plist = (SLTNode*)malloc(sizeof(SLTNode));
  plist = node1;
  SLTPrint(plist);
}

int main()
{
  SLTTest01();
  return 0;
}

