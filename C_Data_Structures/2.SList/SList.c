#include "SList.h"
//链表打印
void SLTPrint(SLTNode * phead)
{
  SLTNode * pcur = phead;
  while (pcur)
  {
    printf("%d->",pcur->data);
    //next 存的是下一个节点的地址，而 pcur 就是一个节点
    pcur = pcur->next;//更新 pcur，找到了下一个节点
  }
  printf("NULL");
  printf("\n");
}

//开辟一个节点，并返回
SLTNode * SLTBuynode(SLTDataType x)
{
  SLTNode * pnewnode = (SLTNode *)malloc(sizeof(SLTNode));
  if (pnewnode == NULL)
  {
    perror("malloc fail!");
    exit(1);
  }
  pnewnode->data = x;
  pnewnode->next = NULL;
  return pnewnode;
}

//尾插：首先要判断是不是空链表，如果是空链表，直接将新创建的节点赋给他
//如果不是空链表，用 while 历遍最后一个节点，并将最后一个节点的 next 连接给新节点
//因为想要改变传过来 plist 内部的值，所以要传地址，又因为传的已经是指针了
//所以需要二级指针来接收指针的地址
//*plist ------- **pphead 结构体
//&plist ------- pphead   结构体指针的地址
//plist --------*pphead   结构体指针
void SLTPush_Back(SLTNode ** pphead,SLTDataType x)
{
  assert(pphead );
  SLTNode * pnewnode = SLTBuynode(x);
   if (*pphead == NULL)
   {
     *pphead = pnewnode;
   }else
   {
     SLTNode *ptail = *pphead;
     while (ptail->next)
     {
       ptail = ptail->next;
     }
      ptail->next = pnewnode;
   }

}

//头插
//创建新的节点并让新的节点连接头节点，随后更新头结点
void SLTPush_Front(SLTNode ** pphead,SLTDataType x)
{
  assert(pphead);
  SLTNode * pnewnode = SLTBuynode(x);
  pnewnode->next = *pphead;
  *pphead = pnewnode;//更新头节点
}

//尾删
//首先要判断是否为空链表，分为空链表和非空链表来处理
//空链表：直接释放然后置为空
//非空链表：找到最后一个节点，释放置为空，再将倒数第二个节点的 next 指针置为空
void SLTPop_Back(SLTNode **pphead)
{
  assert(pphead && *pphead);
  if ((*pphead)->next == NULL)
  {
    free(*pphead);
    *pphead = NULL;//将节点指针置为空
  }else
  {
    SLTNode * ptail = *pphead;
    SLTNode * prev = *pphead;
    while (ptail->next)
    {
      //前后指针法，快慢指针
      //prev 紧跟 ptail 之前
      prev = ptail;
      ptail = ptail->next;
    }
    free(ptail);
    ptail = NULL;
    prev->next = NULL;
  }
}

//头删；先将第一个节点的 next 存储起来防止丢失，然后再删掉
void SLTPop_Front(SLTNode ** pphead)
{
  assert(*pphead && pphead);
  SLTNode * next = (*pphead)->next;
  free(*pphead);
  *pphead = next;
}

//查找:遍历
SLTNode * SLTFind(SLTNode * phead,SLTDataType x)
{
  //尽量保留数据
  SLTNode * pcur = phead;
  assert(pcur);
  while (pcur)
  {
    if (pcur->data == x)
    {
      return pcur;
    }
    pcur = pcur -> next;
  }
  return NULL;
}
//在指定位置前插入
void SLTInsert(SLTNode **pphead,SLTNode *pos,SLTDataType x)
{
  assert(*pphead && pphead);
  assert(pos);
  //当插入第一个之前时，因为没有前面的索引，所以无法插入
  if (*pphead == pos)
  {
    SLTPush_Front(pphead,x);
    return;
  }
  else
  {
    SLTNode * pnewnode = SLTBuynode(x);
    //找到pos 的前一个位置，prev，必须先将 pnewnode 连接到 pos 的位置，在将 prev 和 pnewnode 连接
    //如果先将 prev 连接 pnewnode 就找不到 pos 了
    SLTNode * prev = *pphead;
    while (prev->next != pos)
    {
      prev = prev->next;
    }
    pnewnode ->next = pos;
    prev->next = pnewnode;
  }
}

//在指定位置之后插入数据
//将新的节点先指向pos->next，再将 pos 指向新的节点
void SLTInsertAfter(SLTNode * pos,SLTDataType x)
{
  assert(pos);
  SLTNode * pnewnode = SLTBuynode(x);
  pnewnode->next = pos->next;
  pos->next = pnewnode;
}

//删除pos 节点,需要先判断是不是头结点，如果是 单独的头结点，那 pos->next就为空，需要分情况处理
//先找到 pos 的前一个节点 prev，在找到 pos 的后一个节点，pos->next
//将 prev 连接 pos->next，然后释放 pos 置为空
void SLTErase(SLTNode **pphead,SLTNode *pos)
{
  assert(pphead && *pphead);
  assert(pos);
  // prev pos posnext
  if (pos == *pphead)
  {
    //起始就是头删，直接调用也可以
    SLTNode *next = (*pphead)->next;
    free(*pphead);
    *pphead = next;
    // SLTPop_Front(pphead);
  }else
  {
    SLTNode * prev = *pphead;
    while (prev->next != pos)
    {
      prev = prev->next;
    }
    prev->next =  pos->next;
    free(pos);
    pos = NULL;
  }
}

//删除 pos 的下一个节点
void SLTEraseAfter(SLTNode * pos)
{
  assert(pos && pos->next);
  SLTNode * del = pos->next;
  pos->next = del->next;
  free(del);
}

//链表的销毁
//定义双指针，前后指针进行删除
void SLDestroy(SLTNode ** pphead)
{
  assert(pphead && *pphead);
  SLTNode * pcur = *pphead;
  while (pcur)
  {
    SLTNode * next = pcur->next;
    free(pcur);
    pcur = next;
  }
  *pphead = NULL;
}



