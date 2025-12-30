//
// Created by Dai on 2025/12/29.
//

#include "List.h"

//创建新节点
LTNode * LTbuynode(LTDataType x)
{
  LTNode * node  = (LTNode *)malloc(sizeof(LTNode));
  if (node == NULL)
  {
    perror("malloc fail!");
    exit(1);
  }
  node->data = x;
  node->next = node->prev = node;//双向链表，指向自己
  return node;
}

//初始化
// void LTInit(LTNode **pphead)
// {
//   *pphead = LTbuynode(-1);//哨兵位
// }
LTNode * LTInit()
{
  LTNode * phead = LTbuynode(-1);
  return phead;
}

//打印
void LTprint(LTNode *phead)
{
  LTNode * pcur = phead->next;
  while (pcur != phead)//不等于哨兵位就循环，等于时说明已经遍历完了
  {
    printf("%d->",pcur->data);
    pcur = pcur->next;
  }
  printf("\n");
}


//尾插
//将新节点的 next 指针指向哨兵位，prev 指针指向最后一个节点，phead->prev
//将哨兵位的 prev 更新到 newnode，最后一个节点的 next 指针指向newnode
void LTPushBack(LTNode * phead,LTDataType x)
{
  assert(phead);
  LTNode * newnode = LTbuynode(x);
  //phead  phead->prev newnode
  //先对 newnode 操作
  newnode->prev = phead->prev;
  newnode->next = phead;
  //对 phead->prev，必须先执行最后节点的 next
  phead->prev->next = newnode;
  phead->prev = newnode;
}

//头插
void LTPushFront(LTNode * phead,LTDataType x)
{
  assert(phead);
  //phead newnode phead->next
  LTNode * newnode = LTbuynode(x);
  newnode->prev = phead;
  newnode->next = phead->next;

  phead->next->prev = newnode;
  phead->next = newnode;
}

//查找
LTNode * LTFind(LTNode * phead,LTDataType x)
{
  //pcur指向有效节点
  LTNode * pcur = phead->next;
  while (pcur != phead)
  {
    if (pcur->data == x)
    {
      return pcur;
    }
    pcur = pcur->next;
  }
  return NULL;
}

//尾删
void LTPopBack(LTNode * phead)
{
  assert(phead && phead->next != phead);
  LTNode * del = phead->prev;
  //phead del->prev del
  del->prev->next = phead;
  phead->prev = del->prev;
  //删除 del
  free(del);
  del = NULL;
}

//头删
void LTPopFront(LTNode * phead)
{
  assert(phead && phead->next != phead);
  LTNode * del = phead->next;
  //phead del del->next
  del->next->prev = phead;
  phead->next =  del->next;
  free(del);
  del = NULL;
}

//在指定位置插入
void LTInsert(LTNode * pos,LTDataType x)
{
  assert(pos);
  LTNode * newnode = LTbuynode(x);
  //pos newnode pos->next;
  newnode->prev = pos;
  newnode->next = pos->next;
  pos->next = newnode;
  newnode->next->prev = newnode;
}

//在指定位置删除
void LTErase(LTNode * pos)
{
  assert(pos);
  //pos->prev pos pos->next
  pos->next->prev =pos->prev;
  pos->prev->next = pos->next;
  free(pos);
  pos = NULL;
}

//销毁
void LTDestroy(LTNode * phead)
{
  assert(phead);
  LTNode * pcur = phead->next;
  while (pcur != phead)
  {
    LTNode * next = pcur->next;
    free(pcur);
    pcur = next;
  }
  free(phead);
  phead = NULL;
}