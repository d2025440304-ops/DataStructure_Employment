#include "SeqList.h"//包含头文件，正常使用头文件里所声明的函数
//此文件是测试文件，用来测试顺序表的功能实现是否正常
//测试初始化功能

void SLTest01()
{
    SL sl;
    SLInit(&sl);//传地址调用，如果传值调用，形参是拷贝，但 SL sl没有初始化，所以会报错
}
int main()
{
    SLTest01();
    return 0;
}
