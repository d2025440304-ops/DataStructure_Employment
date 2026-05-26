#include "Sort.h"

void PrintArry(int *a,int sz)
{
  for (int i = 0;i<sz;i++)
  {
    printf("%d ",a[i]);
  }
}

void Swap(int *a,int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void InsertSort(int *a,int sz)
{
  //写排序算法，先写一段的，再写整体
  //排序[0,end]之间保持有序，将 end+1插入
  //换的是 end+1，并不是 end，end+1 = sz-1，end = sz-2
  for(int i = 0;i<sz-1;i++)
  {
      //单趟
    int end = i;
    int tmp = a[end+1];
    while(end >= 0)
    {
      if(tmp < a[end])
      {
        a[end+1] = a[end];
        end--;
      }else{
        break;
      }
    }
    a[end+1] = tmp;
  }
}


void AdjustDown(int *a,int n,int parent)
{
  int child = 2*parent+1;
  while (child < n)
  {
    if (child+1 < n && a[child] < a[child+1])
    {
      child++;
    }
    if (a[child] > a[parent])
    {
      Swap(&a[child],&a[parent]);
      parent = child;
      child = 2*parent+1;
    }
    else
    {
      break;
    }
  }
}

void HeapSort(int * a,int n)
{
  //建堆，从最后一个非空子树开始向下调整,
  for(int i = (n-2)/2;i>=0;i--)
  {
    AdjustDown(a,n,i);
  }
  for (int end = n-1; end > 0; end--)
  {
    Swap(&a[0],&a[end]);
    AdjustDown(a,end,0);
  }
}

void BubbleSort(int *a,int n)
{
  for(int j = 0;j<n-1;j++)
  {
    //单趟
    for(int i = 1;i<n-j;i++)
    {
      if(a[i-1] > a[i])
      {
        Swap(&a[i-1],&a[i]);
      }
    }
  }
}

void ShellSort(int *a ,int n)
{
  //gap 组，下标为 gap-1 时已经覆盖全部元素
  // for(int j = 0;j<gap;j++)
  // {
  //   //进行一组排序
  //   for(int i = j;i < n-gap; i+=gap)
  //   {
  //     int end = i;
  //     int tmp = a[end+gap];
  //     //进行单次的排序
  //     while(end >= 0)
  //     {
  //       if(tmp < a[end])
  //       {
  //         a[end+gap] = tmp;
  //         end-=gap;
  //       }else break;
  //     }
  //     a[end+1] = tmp;
  //   }
  // }
  int gap = n;
  while(gap > 1)
  {
    gap = gap/3 + 1;
    for(int i = 0;i < n-gap; i++)
    { 
      int end = i;
      int tmp = a[end+gap];
      //进行单次的排序
      while(end >= 0) 
      {
        if(tmp < a[end])
        {
          a[end+gap] = a[end];
          end-=gap;
        }else break;
      }
      a[end+gap] = tmp;
    }
  }
}