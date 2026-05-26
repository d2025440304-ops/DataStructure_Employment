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

  return 0;
}