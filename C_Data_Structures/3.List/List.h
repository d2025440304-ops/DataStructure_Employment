#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef  int LTDataType;
//定义结构体
typedef struct Listnode
{
  LTDataType data;
  struct Listnode * next;
  struct Listnode * prev;
}LTNode;

//声明双向链表的方法

//初始化
// void LTInit(LTNode ** pphead);
LTNode * LTInit();

//打印双向链表
void LTprint(LTNode *phead);

//尾插
void LTPushBack(LTNode * phead,LTDataType x);
void LTPushFront(LTNode * phead,LTDataType x);

//头删，尾删
void LTPopBack(LTNode * phead);
void LTPopFront(LTNode * phead);

//查找
LTNode * LTFind(LTNode * phead,LTDataType x);

//在指定位置插入
void LTInsert(LTNode * pos,LTDataType x);

//在指定位置删除
void LTErase(LTNode * pos);

//销毁
void LTDestroy(LTNode * phead);

