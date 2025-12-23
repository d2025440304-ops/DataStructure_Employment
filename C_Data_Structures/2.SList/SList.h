#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//定义一个节点，在节点里有存储数据和指向下一个结构体的指针

//存储数据的类型
typedef int SLTDataType;

//节点
typedef struct SListNode
{
  SLTDataType data;//数据
  struct SListNode *next;//指针索引
}SLTNode;

//链表的打印
void SLTPrint(SLTNode *phead);

//链表的尾插
void SLTPush_Back(SLTNode *phead,SLTDataType data)
{

}
