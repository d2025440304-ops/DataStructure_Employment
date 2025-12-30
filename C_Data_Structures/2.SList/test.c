#include "SList.h"
//测试
// void SLTTest01()
// {
//   //定义节点，并为节点开辟空间
//   SLTNode * node1 = (SLTNode *)malloc(sizeof(SLTNode));
//   node1->data = 1;
//   SLTNode * node2 = (SLTNode  *)malloc(sizeof(SLTNode));
//   node2->data = 2;
//   SLTNode * node3 = (SLTNode *)malloc(sizeof(SLTNode));
//   node3->data = 3;
//   SLTNode * node4 = (SLTNode *)malloc(sizeof(SLTNode));
//   node4->data = 4;
//   //将节点中的指针指向下一个节点
//   node1->next = node2;
//   node2->next = node3;
//   node3->next = node4;
//   node4->next = NULL;
//   SLTNode *plist = (SLTNode*)malloc(sizeof(SLTNode));
//   plist = node1;
//   SLTPrint(plist);
// }

void SLTTest02()
{
  SLTNode * plist = NULL;
  //尾插
  SLTPush_Back(&plist,1);
  SLTPush_Back(&plist,2);
  SLTPush_Back(&plist,3);
  SLTPush_Back(&plist,4);
  SLTPush_Back(&plist,5);
  SLTPush_Back(&plist,6);
  //头插
  SLTPush_Front(&plist,1);
  //头删
  // SLTPop_Front(&plist);
  // SLTPop_Front(&plist);
  // SLTPop_Front(&plist);
  // SLTNode * pp = SLTFind(plist,4);
  // if (pp==NULL)
  // {
  //   printf("找不到\n");
  // }else
  //   printf("找到了\n");
  //指定位置插入
  // SLTInsert(&plist,pp,3);
  //指定位置之后插入
  // SLTInsertAfter(pp,3);
  // //指定位置删除
  // SLTErase(&plist,pp);

  SLTPrint(plist);
}

int main()
{
  // SLTTest01();
  SLTTest02();
  return 0;
}

