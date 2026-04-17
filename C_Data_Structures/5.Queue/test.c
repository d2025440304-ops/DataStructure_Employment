#include <queue.h>
int main()
{
  Que pq;;
  QueInit(&pq);
  QuePush(&pq,1);
  QuePush(&pq,2);
  QuePush(&pq,3);
  QuePush(&pq,4);
  QuePush(&pq,5);

  while (!QueEmpty(&pq))
  {
    printf("%d ",QueFront(&pq));
    QuePop(&pq);
  }
  QueDestroy(&pq);
  return 0;
}