#include "Heap.h"

void HPInit(HP * hp)
{
  hp->a = NULL;
  hp->size = hp->capacity = 0;
}

void HPDestory(HP * hp)
{
  //free： malloc，calloc，realloc
  assert(hp);
  free(hp->a);
  hp->a = NULL;
  hp->size = hp->capacity = 0;
}

void Swap(HPDataType *child,HPDataType * parent)
{
  HPDataType  x = *child;
  *child = * parent;
  *parent = x;
}

void AdjustUp(HPDataType * a,HPDataType child)
{
  assert(a);
  int parent = (child-1)/2;
  while (child > 0)
  {
    if (a[child] < a[parent])
    {
      Swap(&a[child],&a[parent]);
      child = parent;
      parent = (child-1)/2;
    }else break;
  }
}

void HPpush(HP *hp,HPDataType x)
{
  if (hp->size == hp->capacity)
  {
    int newcapacity = hp->capacity == 0 ? 4 : 2*hp->capacity;
    HPDataType * tmp = (HPDataType *)realloc(hp->a,sizeof(HPDataType)*newcapacity);
    if (tmp == NULL)
    {
      perror("realloc fail");
      return ;
    }
    hp->a = tmp;
    hp->capacity = newcapacity;
  }

  hp->a[hp->size++] = x;
  int child = hp->size-1;
  AdjustUp(hp->a,child);
}

void Adjustlow(HPDataType *a ,int parent,int size)
{
  int child = 2*parent+1;
  while (child < size)
  {
    if (child + 1 <size && a[child+1] < a[child])
    {
      child++;
    }

    if (a[child] < a[parent])
    {
      Swap(&a[child],&a[parent]);
      parent = child;
      child = 2*parent+1;
    }else break;
  }
}

void HPpop(HP * hp)
{
  assert(hp);
  assert(hp->size > 0);
  Swap(&hp->a[0],&hp->a[hp->size-1]);
  hp->size--;
  Adjustlow(hp->a,0,hp->size);
}

HPDataType HPtop(HP * hp)
{
  assert(hp);
  assert(hp->size > 0);
  return hp->a[0];
}

bool HPempty(HP *hp)
{
  return hp->size == 0;
}

