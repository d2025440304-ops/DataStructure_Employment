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

// 关键点：max/min 都要从 begin 开始遍历整个区间，不能漏掉 begin 位置
// O(N^2)
void SelectSort(int *a,int n)
{
  int begin = 0,end = n-1;
  while(begin < end)
  {
    int maxi = begin,mini = begin;
    for(int i = mini+1;i <= end;i++)
    {
      if(a[i] > a[maxi])
      {
        maxi = i;
      }
      if(a[i] < a[mini])
      {
        mini = i;
      }
    }
    Swap(&a[mini],&a[begin]);
    if(maxi == begin)
    {
      maxi = mini;
    }
    Swap(&a[maxi],&a[end]);
    begin++;
    end--;
  }
}

// 一趟划分：以第一个元素为基准，将数组分成 [小, 基准, 大] 三部分
// 返回基准值最终位置的索引

//三数取中，三个数左中右，取大小是中间的那个下标
int Getmidi(int *a,int left,int right)
{
  int midi =  (left+right)/2;
  if(a[left] < a[midi])
  {
    if(a[midi] < a[right])
    {
      return midi;
    }
    else if(a[left] < a[right])
    {
      return right;
    }
    else return left;
  }
  else{
    //a[left] > a[midi]
    if(a[right] > a[left])
    {
      return left;
    }
    else if(a[midi] > a[right])
    {
      return midi;
    }
    else return right;
  }
}

void QuickSort(int *a, int left, int right)
{
  if (left >= right)
    return;

  int midi = Getmidi(a,left,right);
  Swap(&a[midi],&a[left]);
  int keyi = left;
  int begin = left,end = right;
  while(begin < end)
  {
    while(begin < end && a[end] >= a[keyi])
    {
      end--;
    }

    while(begin < end && a[begin] <= a[keyi])
    {
      begin++;
    }
    
    Swap(&a[begin],&a[end]);
  }
  Swap(&a[keyi],&a[end]);
  keyi = begin;
  QuickSort(a,left,keyi-1);
  QuickSort(a,keyi+1,right);
}

void quicksort_(int *a,int left,int right)
{
  int i = 0,L = -1,R = right-1;
  int key = 0;
  while(i < R)
  {
    if(a[i] == a[key])  swap(a[++L],a[i++]);
    else if(a[i] < a[key])
  }
}

// 三路快速排序（Dutch National Flag 划分）
// 一次划分将数组分为 < key / = key / > key 三段，= key 段不再递归
// 优势：解决大量重复元素时 QuickSort 退化为 O(N²) 的问题
// pivot 选取：复用 Getmidi 取三数中值，避免极端有序数据退化
void QuickSort3Way(int *a,int left,int right)
{
  if (left >= right)
    return;

  // 选 pivot 并交换到 left 位置
  int midi = Getmidi(a,left,right);
  Swap(&a[midi],&a[left]);
  int key = a[left];

  // 三个游标维护循环不变量：
  // a[left ... lt-1]   < key
  // a[lt   ... i-1]    = key
  // a[i    ... gt]     尚未处理
  // a[gt+1 ... right]  > key
  int lt = left;     // < key 区间的右端（开区间）
  int gt = right;    // > key 区间的左端（开区间）
  int i = left;      // 当前考察元素

  while (i <= gt)
  {
    if (a[i] < key)
    {
      // 把 a[i] 换到 < key 区间末尾，lt 区间扩大
      Swap(&a[i],&a[lt]);
      lt++;
      i++;
    }
    else if (a[i] > key)
    {
      // 把 a[i] 换到 > key 区间开头，gt 区间扩大
      // 注意：i 不递增，因为换过来的 a[gt] 还没检查过
      Swap(&a[i],&a[gt]);
      gt--;
    }
    else  // a[i] == key
    {
      i++;
    }
  }

  // 递归时跳过 = key 部分
  QuickSort3Way(a,left,lt-1);
  QuickSort3Way(a,gt+1,right);
}