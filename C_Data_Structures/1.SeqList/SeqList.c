#include "SeqList.h"

//此 SeqList.c文件用来实现顺序表的方法
// .c文件做出函数的定义，只要包括.h 文件的头文件，在.h文件里做出了定义，就可以用声明了的函数
//初始化顺序表函数

void SLInit(SL* ps)
{
    ps->arr = 0;
    ps->capacity = ps->size = 0;
}