#include "SeqList.h"//包含头文件，正常使用头文件里所声明的函数
//此文件是测试文件，用来测试顺序表的功能实现是否正常
//测试初始化功能

// void SLTest01()
// {
//     SL sl;
//
//     SLInit(&sl);//初始化
//   //测试尾插
//     SLPushBack(&sl,1);
//     SLPushBack(&sl,2);
//     SLPushBack(&sl,3);
//     SLPushBack(&sl,4);
//     SLPushBack(&sl,5);
//     SLPrint(sl);//打印
//
//   // //测试头插
//   //   SLPushFront(&sl,6);
//   //   SLPushFront(&sl,7);
//   //   SLPrint(sl);//打印
//
//   // //测量头删
//   //   SLPopFront(&sl);
//   // SLPrint(sl);
//   //   SLPopFront(&sl);
//   // SLPrint(sl);
//   //   SLPopFront(&sl);
//   // SLPrint(sl);
//   //   SLPopFront(&sl);
//   // SLPrint(sl);
//   //   SLPopFront(&sl);
//   // SLPrint(sl);
//
//   //测量尾删
//     SLPopBack(&sl);
//   SLPrint(sl);
//   SLPopBack(&sl);
//   SLPrint(sl);
//   SLPopBack(&sl);
//   SLPrint(sl);
//   SLPopBack(&sl);
//   SLPrint(sl);
//   SLPopBack(&sl);
//   SLPrint(sl);
//     SLDestroy(&sl);//销毁
// }

void SLTest02()
{
  SL sl;
  SLInit(&sl);
  //测试尾插
  SLPushBack(&sl,1);
  SLPushBack(&sl,2);
  SLPushBack(&sl,3);
  SLPushBack(&sl,4);
  SLPushBack(&sl,5);
  SLPrint(sl);//打印
//测试指定位置插入
  // SLInsert(&sl,3,99);//1,2,3,99,4,5中间插入
  // SLPrint(sl);//打印
  // SLInsert(&sl,0,88);//88,1,2,3,99,4,5头插
  // SLPrint(sl);//打印
  // SLInsert(&sl,5,10);//尾插
  // SLPrint(sl);//打印

  //测试指定位置的删除
  SLErase(&sl,2);
  SLPrint(sl);
  //销毁
  SLDestroy(&sl);
}

int main()
{
    // SLTest01();
    SLTest02();
    return 0;
}
