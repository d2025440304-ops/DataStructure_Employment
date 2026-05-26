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

int main()
{
  printf("InsertSort: ");
  TestInsertsort();
  printf("\n");

  printf("HeapSort:   ");
  TestHeapsort();
  printf("\n");

  return 0;
}