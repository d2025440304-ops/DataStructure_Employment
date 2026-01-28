#include "Stack.h"

//初始化
void STInit(ST *pst)
{
  assert(pst);
  pst->arr = NULL;
  //此时的 top 指向栈顶的下一个元素
  pst->top = 0;
  // //此时的 top 指向栈顶元素
  // pst->top = -1;
  pst->capacity = 0;
}
//栈的销毁
void STDestroy(ST * pst)
{
  free(pst->arr);
  pst->arr = NULL;
  pst->capacity = pst->top = 0;
}
//入栈
void STPush(ST * pst,STDataType x)
{
  assert(pst);
  if (pst->top == pst->capacity)
  {
    int newcapacity = pst->capacity== 0 ? 4 : 2*pst->capacity;
    STDataType * tmp = (STDataType *)realloc(pst->arr,newcapacity*sizeof(STDataType));
    if (tmp == NULL)
    {
      perror("realloc fail");
      return;
    }
    pst->arr = tmp;
    pst->capacity = newcapacity;
  }
  pst->arr[pst->top++] = x;
}
//出栈
void STPop(ST * pst)
{
  assert(pst);
  assert(pst->top > 0);
  pst->top--;
}

//判断栈是否为空
bool STEmpty(ST * pst)
{
  assert(pst);
  return pst->top == 0;
}

//求栈顶元素
STDataType STTop(ST * pst)
{
  assert(pst);
  assert(pst->top>0);
  return pst->arr[pst->top-1];
}
//栈里的元素个数
int STSize(ST * pst)
{
  assert(pst);
  return pst->top;
}