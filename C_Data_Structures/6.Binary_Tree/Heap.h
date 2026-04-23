#pragma once
//小根堆
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct
{
  HPDataType * a;
  int size;
  int capacity;
}HP;//HP为容器

void Swap(HPDataType *child,HPDataType * parent);
void AdjustUp(HPDataType * a,int child);
void Adjustlow(HPDataType *a,int parent,int size);
void HPInit(HP * hp);
void HPDestory(HP *hp);
void HPpush(HP * hp,HPDataType x);
void HPpop(HP * hp);
HPDataType HPtop(HP *hp);
bool HPempty(HP *hp);
