#include "SeqList.h"//包含头文件，正常使用头文件里所声明的函数
//此文件是测试文件，用来测试顺序表的功能实现是否正常
//测试初始化功能

void SLTest01()
{
    SL sl;
    SLInit(&sl);//初始化
    SLPushBack(&sl,4);
    SLDestory(&sl);//销毁
}
int main()
{
    SLTest01();
    return 0;
}
