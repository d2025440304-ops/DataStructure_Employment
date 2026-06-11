#include "Sort.h"

void TestInsertsort()
{
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int sz = sizeof(arr)/sizeof(arr[0]);
  InsertSort(arr,sz);
  PrintArry(arr,sz);
}

void TestHeapsort()
{
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int sz = sizeof(arr)/sizeof(arr[0]);
  HeapSort(arr,sz);
  PrintArry(arr,sz);
}

void TestBubblesort()
{
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int sz = sizeof(arr)/sizeof(arr[0]);
  BubbleSort(arr,sz);
  PrintArry(arr,sz);
}

void TestShellsort()
{
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int sz = sizeof(arr)/sizeof(arr[0]);
  ShellSort(arr,sz);
  PrintArry(arr,sz);
}

void TestSelectsort()
{
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int sz = sizeof(arr)/sizeof(arr[0]);
  SelectSort(arr,sz);
  PrintArry(arr,sz);
}

void TestQuicksort()
{
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int sz = sizeof(arr)/sizeof(arr[0]);
  QuickSort(arr,0,sz-1);
  PrintArry(arr,sz);
}

void TestQuickSort3Way()
{
  int sz;

  // 1. 全相等（传统快排会退化）
  int a1[] = {5,5,5,5,5,5};
  sz = sizeof(a1)/sizeof(a1[0]);
  QuickSort3Way(a1,0,sz-1);
  printf("[all equal]    "); PrintArry(a1,sz); printf("\n");

  // 2. 大量重复
  int a2[] = {1,2,1,2,1,2,1,2,1,2};
  sz = sizeof(a2)/sizeof(a2[0]);
  QuickSort3Way(a2,0,sz-1);
  printf("[many dup]     "); PrintArry(a2,sz); printf("\n");

  // 3. 已排序
  int a3[] = {1,2,3,4,5,6,7,8,9};
  sz = sizeof(a3)/sizeof(a3[0]);
  QuickSort3Way(a3,0,sz-1);
  printf("[sorted]       "); PrintArry(a3,sz); printf("\n");

  // 4. 逆序
  int a4[] = {9,8,7,6,5,4,3,2,1};
  sz = sizeof(a4)/sizeof(a4[0]);
  QuickSort3Way(a4,0,sz-1);
  printf("[reverse]      "); PrintArry(a4,sz); printf("\n");
}

int main()
{
  printf("InsertSort: ");
  TestInsertsort();
  printf("\n");

  printf("HeapSort:   ");
  TestHeapsort();
  printf("\n");

  printf("BubbleSort:  ");
  TestBubblesort();
  printf("\n");

  printf("ShellSort:  ");
  TestShellsort();
  printf("\n");

  printf("SelectSort: ");
  TestSelectsort();
  printf("\n");

  printf("QuickSort:  ");
  TestQuicksort();
  printf("\n");

  printf("\n--- QuickSort3Way ---\n");
  TestQuickSort3Way();

  return 0;
}