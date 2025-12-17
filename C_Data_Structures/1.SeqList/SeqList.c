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
void SLDestory(SL * ps)
{
    if (ps->arr)
    {
        free(ps->arr);//在 arr 进行动态内存开辟之后
    }
    ps->arr = NULL;
    ps->capacity = ps->size = 0;
}


// 顺序表的的尾插
 void SLPushBack(SL * ps ,SLDataType n)
{
    //如果传的是空指针的话，就会出问题，报错，用断言、
    assert(ps);
    /*在插入前，/*应该先判断空间是否足够插入
    因为数组的下标为 0，所以 当前的size即数组中元素个数就是尾部插入的位置
    而判断空间是否足够，就要看 size 和 capacity 是否相等，如果相等，那就不够用
    举例，当size是 6 时，待插的元素下标就是 6，而空间必须是 7
    如果空间也是 6 的话，,空间不足就会越界访问#1#*/
    if (ps->size == ps->capacity)
    {
        //增加空间前还要判断 capacity 是否为 0
        //增容增多大的空间呢？最好增目前两倍的空间
        int Newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        SLDataType * tmp = (SLDataType *)realloc(ps->arr,Newcapacity*sizeof(SLDataType));
        //要检查是否申请成功
        if (tmp == NULL)
        {
            perror("realloc file");
            exit(0);
        }
        ps->arr = tmp;//交给 arr 来维护
        tmp = NULL;
        ps->capacity = Newcapacity;
    }
    ps->arr[ps->size++] = n;//后置++，先使用 size 再让 size 更新记录
}
