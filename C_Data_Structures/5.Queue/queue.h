#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDatatype;

typedef struct QueueNode
{
  QDatatype data;
  struct QueueNode * next;
}QNode;

//将整个队列用头节点和尾节点管理
typedef struct Queue
{
  QNode * phead;
  QNode * ptail;
  int size;
}Que;

void QueInit(Que * pq);
void QueDestroy(Que * pq);

void QuePush(Que * pq,QDatatype x);

void QuePop(Que * pq);

QDatatype QueFront(Que * pq);

QDatatype QueBack(Que * pq);

bool QueEmpty(Que * pq);
