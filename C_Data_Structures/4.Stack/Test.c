#include "Stack.h"
// int main()
// {
//   ST s;
//   STInit(&s);
//   STPush(&s,1);
//   STPush(&s,2);
//   STPush(&s,3);
//   STPush(&s,4);
//   STPush(&s,5);
//   printf("%d\n",STTop(&s));
//   STPop(&s);
//   printf("%d\n",STTop(&s));
//   return 0;
// }

int main()
{
  ST s;
  STInit(&s);
  STPush(&s,1);
  STPush(&s,2);
  STPush(&s,3);
  STPush(&s,4);
  STPush(&s,5);
  //访问栈内的所有元素
  while (!STEmpty(&s))
  {
    printf("%d ",STTop(&s));
    STPop(&s);
  }
  return 0;
}