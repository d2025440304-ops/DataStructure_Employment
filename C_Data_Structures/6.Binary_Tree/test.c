#include "Heap.h"

HP hp;
// void test1()
// {
//   int a[] = {9,8,7,6,6,5,4,3};
//   int size = sizeof(a)/sizeof(int);
//   HPInit(&hp);
//   for (int i = 0;i<size;i++)
//   {
//     HPpush(&hp,a[i]);
//   }
//
//   for (int i = 0;i<size;i++)
//   {
//     printf("%d ",hp.a[i]);
//   }
//   HPDestory(&hp);
// }

// void hpsort()
// {
//   int a[] = {9,8,7,6,6,5,4,3};
//   int size = sizeof(a)/sizeof(int);
//   HP hp;
//   HPInit(&hp);
//   for (int i = 0;i<size;i++)
//   {
//     HPpush(&hp,a[i]);
//   }
//   while(!HPempty(&hp))
//   {
//     printf("%d ",HPtop(&hp));
//     HPpop(&hp);
//   }
//   int i =0;
//   while(!HPempty(&hp))
//   {
//     a[i++] = HPtop(&hp);
//     HPpop(&hp);
//   }
// }

// void topk()
// {
//   int k;
//   scanf("%d",&k);
//   while (k--)
//   {
//     printf("%d ",HPtop(&hp));
//     HPpop(&hp);
//   }
// }
//
void HeapSort()
{
  //堆排序，降序-小根堆
  int arr[] = {9,7,6,5,4,2,8};
  int sz = sizeof(arr)/sizeof(int);
  //默认第一个元素是合法的小根堆，在插入向上调整
  for (int i = 1;i<sz;i++)
  {
    //默认第一个元素是小根堆，对每一个元素都向上调整
    AdjustUp(arr,i);//数组地址，下标
  }
  int end = sz-1;
  while (end > 0)
  {
    Swap(&arr[0],&arr[end]);
    Adjustlow(arr,0,end);
    end--;
  }

  for (int i = 0;i<sz;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}
int main()
{
  // test1();
  // hpsort();
  HeapSort();
  return 0;
}