#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N 100

//在.h文件中，是声明结构体和函数等顺序表的方法


//Sequential List顺序表
//在数据结构中，有线性表，在线性表中，逻辑是连续的，但结构不一定连续，而顺序表是线性表的一种
//在顺序表中，结构是连续的，逻辑也是连续的
//顺序表的底层是数组，但顺序表更加高级，可以实现增删改查的功能

typedef int SLDataType;
//静态顺序表
struct SeqList
{
    SLDataType arr[N];//一个足够大的静态数组
    int size;//用来记录数组中使用的元素
};


//动态顺序表
//讲顺序表结构体类型重命名为SL
typedef struct SeqList_
{
    SLDataType *arr;//因为是动态，所以用一个指针，方便后续使用 malloc，realloc，calloc
    int size;//用来记录使用的个数
    int capacity;//用来记录目前的空间
}SL;

//顺序表打印函数
void SLPrint(SL s);

//顺序表的初始化
void SLInit(SL *ps);

//顺序表的销毁；
void SLDestroy(SL *ps);

//顺序表的尾插/头插
void SLPushBack(SL * ps ,SLDataType n);//尾插 当前的数据类型
void SLPushFront(SL * ps ,SLDataType n);//头插

//顺序表的删除
void SLPopBack(SL *ps);
void SLPopFront(SL *ps);