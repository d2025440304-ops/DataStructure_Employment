#include "Sort.h"

void PrintArry(int *a,int sz)
{
  for (int i = 0;i<sz;i++)
  {
    printf("%d ",a[i]);
  }
}



void InsertSort(int *a,int sz)
{
  //写排序算法，先写一段的，再写整体
  //排序[0,end]之间保持有序，将 end+1插入
  //换的是 end+1，并不是 end，end+1 = sz-1，end = sz-2
  for (int i = 0;i<sz-1;i++)
  {
    int end = i;
    int tmp = end+1;
    while (end >= 0)
    {
      if (tmp < a[end])
      {
        a[end+1] = a[end];
        end--;
      }
      else
      {
        break;
      }
    }
    a[end+1] = tmp;
  }
}
