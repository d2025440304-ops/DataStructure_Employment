#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//用数组来实现栈，先进后出的数据结构
#define N 10;
typedef  int STDataType;
typedef struct stack
{
  STDataType * arr ;
  int top;
  int capacity;//容量
}ST;

//初始化和销毁
void STInit(ST *pst);
void STDestroy(ST * pst);

//入栈 和 出栈
void STPush(ST * pst,STDataType x);
void STPop(ST * pst);

//判断栈是否为空
bool STEmpty(ST * pst);

//获取顶部数据
STDataType STTop(ST * pst);

//获取栈中的个数
int STSize(ST * pst);