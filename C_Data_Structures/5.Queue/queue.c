#include "queue.h"
void QueInit(Que * pq)
{
  assert(pq);
  pq->size = 0;
  pq->phead = pq->ptail = NULL;
}

//尾插
void QuePush(Que * pq,QDatatype x)
{
  //pq是装了头尾节点的结构体，nwenode 是一个节点
  assert(pq);
  QNode * newnode = (QNode *)malloc(sizeof(QNode));
  if (newnode == NULL)
  {
    perror("malloc fail");
    return;
  }
  newnode->next = NULL;
  newnode->data = x;
  if (pq->ptail == NULL)
  {
    pq->phead = pq->ptail = newnode;
  }
  else
  {
    pq->ptail->next = newnode;
    pq->ptail = newnode;
  }
   pq->size++;
}
//队列数量
int Quesize(Que * pq)
{
  assert(pq);
  return pq->size;
}

//头删
void QuePop(Que * pq)
{
  assert(pq);
  assert(pq->size != 0);

  if (pq->phead->next == NULL)
  {
    free(pq->phead);
    pq->phead = pq->ptail = NULL;
  }
  else
  {
    QNode * next = pq->phead->next;
    free(pq->phead);
    pq->phead = next;
  }
  pq->size--;
}

//取队头
QDatatype QueFront(Que * pq)
{
  assert(pq);
  assert(pq->phead);
  return pq->phead->data;
}

//取队尾
QDatatype QueBack(Que *pq)
{
  assert(pq);
  assert(pq->ptail);
  return pq->ptail->data;
}

//判空
bool QueEmpty(Que* pq)
{
  assert(pq);
  return pq->size == 0;
}

//销毁
void QueDestroy(Que * pq)
{
  assert(pq);
  QNode * cur = pq->phead;
  while (cur)
  {
    QNode * next = cur->next;
    cur = NULL;

    cur = next;
  }
  pq->phead = pq->ptail = NULL;
  pq->size = 0;
}


