//
// Created by Dai on 2025/12/29.
//
#include "../2.SList/SList.h"
#include "List.h"
void Test01()
{
  // LTNode * plist = NULL;
  //初始化
  LTNode * plist = LTInit();
  //尾插
  LTPushBack(plist,1);
  LTPushBack(plist,2);
  LTPushBack(plist,3);
  //头插
  // LTPushFront(plist,4);
  //尾删
  // LTPopBack(plist);
  // //头删
  // LTPopFront(plist);
  //查找
  LTNode * find = LTFind(plist,2);
  if (find != NULL)
  {
    printf("存在");
  }
  //指定位置插入
  LTInsert(find,4);
  LTErase(find);
  find = NULL;
  LTprint(plist);
  LTDestroy(plist);

  plist = NULL;
}
int main()
{
  Test01();
  return 0;
}
