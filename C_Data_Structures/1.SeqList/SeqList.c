#include "SeqList.h"

//此 SeqList.c文件用来实现顺序表的方法
// .c文件做出函数的定义，只要包括.h 文件的头文件，在.h文件里做出了定义，就可以用声明了的函数


//初始化顺序表函数
void SLInit(SL* ps)
{
    ps->arr = 0;
    ps->capacity = ps->size = 0;
}

//销毁顺序表
void SLDestroy(SL * ps)
{
    if (ps->arr)
    {
        free(ps->arr);//在 arr 进行动态内存开辟之后
    }
    ps->arr = NULL;
    ps->capacity = ps->size = 0;
}

//顺序表打印函数
void SLPrint(SL s)
{
  for (int i = 0;i<s.size;i++)
  {
    printf("%d ",s.arr[i]);
  }
  printf("\n");
}



//检查存储容量
void SLCheckcapacity(SL *ps)
{
    // 在插入前，应该先判断空间是否足够插入
    // 因为数组的下标为 0，所以 当前的size即数组中元素个数就是尾部插入的位置
    // 而判断空间是否足够，就要看 size 和 capacity 是否相等，如果相等，那就不够用
    // 举例，当size是 6 时，待插的元素下标就是 6，而空间必须是 7
    // 如果空间也是 6 的话，,空间不足就会越界访问1
    if (ps->size == ps->capacity)
    {
        //增加空间前还要判断 capacity 是否为 0
        //增容增多大的空间呢？最好增目前两倍的空间
        int Newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
      SLDataType * tmp  = (SLDataType *)realloc(ps->arr,Newcapacity*sizeof(SLDataType));
        //要检查是否申请成功
        if (tmp == NULL)
        {
            perror("realloc fail");
            exit(0);
        }
        ps->arr = tmp;//交给 arr 来维护
        tmp = NULL;
        ps->capacity = Newcapacity;//空间内容也要更新
    }
}


// 顺序表的的尾插
 void SLPushBack(SL * ps ,SLDataType n)
{
    //如果传的是空指针的话，就会出问题，报错，用断言、
    assert(ps);

    //检查内存容量
    SLCheckcapacity(ps);

    //尾插
    ps->arr[ps->size++] = n;//后置++，先使用 size 再让 size 更新记录
}

//顺序表的头插
void SLPushFront(SL *ps,SLDataType n)
{
    assert(ps);
    //判断空间
    SLCheckcapacity(ps);
    //因为是头插，所以要讲数据往后移
    for (int i = ps->size;i>0;i--)
    {
        ps->arr[i] = ps->arr[i-1];
    }
    ps->arr[0] = n;
    //在插入完成后，size 要更新
    ps->size++;//更新 size
}

//顺序表的删除
//末尾删除
void SLPopBack(SL *ps)
{
  assert(ps);
  assert(ps->size);//数据个数不能为空
  ps->size--;//直接覆盖，当进行增删查改时，不影响，而且效率更高，惰性删除
}
//头部删除
void SLPopFront(SL *ps)
{
  assert(ps);
  assert(ps->size);
  //头删也就是将后面的数据覆盖到第一个，并且 size--
  for (int i = 0;i<ps->size-1;i++)
  {
    ps->arr[i] = ps->arr[i+1];
  }
  ps->size--;
}

//顺序表指定位置的插入
void SLInsert(SL *ps,int pos,SLDataType n)
{
  assert(ps);
  //临界情况就是头插和尾插
  assert(pos >= 0 && pos <= ps->size);
  //插入前要将待插入位置及以后的数据向后挪动
  for (int i = ps->size;i>pos;i--)
  {
    ps->arr[i] = ps->arr[i-1];
  }
  ps->arr[pos] = n;
  ps->size++;
}

//顺序表的指定位置删除
void SLErase(SL * ps ,int pos)
{
  assert(ps);
  assert(pos >= 0 && pos < ps->size);
  //将要删除位置的数据以后的数据往前移动，覆盖数组
  for (int i =pos;i<ps->size-1;i++)
  {
    ps->arr[i] = ps->arr[i+1];
  }
  ps->size--;
}

//顺序表的查找
int SLFind(SL *ps,SLDataType n)
{
  assert(ps);
  for (int i = 0;i<ps->size;i++)
  {
    if (ps->arr[i] == n)
    {
      //找到了
      return i;
    }
  }
  return -1;
}

