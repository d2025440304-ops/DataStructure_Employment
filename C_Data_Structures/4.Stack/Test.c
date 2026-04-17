#include "Stack.h"

void test()
{
  ST st;
  ST *pst = &st;
  STInit(pst);
  STPush(pst, 1);
  STPush(pst, 2);
  STPush(pst, 3);
  STPush(pst, 4);

  while (!STEmpty(pst))
  {
    printf("%d ", STTop(pst));
    STPop(pst);
    printf("\n");
  }
  STDestroy(pst);
}

int main()
{
  test();
}