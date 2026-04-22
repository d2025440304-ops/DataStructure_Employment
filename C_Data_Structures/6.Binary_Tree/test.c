#include "Heap.h"

void test1()
{
  int a[] = {9,8,7,6,6,5,4,3};
  int size = sizeof(a)/sizeof(int);
  HP hp;
  HPInit(&hp);
  for (int i = 0;i<size;i++)
  {
    HPpush(&hp,a[i]);
  }

  for (int i = 0;i<size;i++)
  {
    printf("%d ",hp.a[i]);
  }
  HPDestory(&hp);
}

void hpsort()
{
  int a[] = {9,8,7,6,6,5,4,3};
  int size = sizeof(a)/sizeof(int);
  HP hp;
  HPInit(&hp);
  for (int i = 0;i<size;i++)
  {
    HPpush(&hp,a[i]);
  }
  for (int i = 0;i<size;i++)
  {
    printf("%d ",HPtop(&hp));
    HPpop(&hp);
  }
}
int main()
{
  test1();
  hpsort();
  return 0;
}