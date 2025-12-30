#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//链表是一种线性表，逻辑结构是连续的
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
void SLTPrint(SLTNode *pphead);

//链表的尾插
void SLTPush_Back(SLTNode **pphead,SLTDataType x);
//链表的头插
void SLTPush_Front(SLTNode **pphead,SLTDataType x);

//链表的尾删
void SLTPop_Back(SLTNode **pphead);
//链表的头删
void SLTPop_Front(SLTNode ** pphead);

//链表的查找
SLTNode * SLTFind(SLTNode * phead,SLTDataType x);

//在指定位置之前插入数据
void SLTInsert(SLTNode **pphead,SLTNode * pos,SLTDataType x);

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode *phead,SLTDataType x);

//删除 pos 节点
void SLTErase(SLTNode ** pphead,SLTNode * pos);

//删除 pos 之后的节点
void SLTEraseAfter(SLTNode * pos);

//销毁链表
void SLDestroy(SLTNode ** pphead);