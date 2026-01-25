//
// Created by Dai on 2026/1/11.
//

#include "Stack.h"
//初始化
void STInit(ST *pst);
//栈的销毁
void STDestroy(ST * pst);
//入栈
void STPush(ST * pst);
//出栈
void STPop(ST * pst);
//判断栈是否为空
bool STEmpty(ST * pst);
//求栈顶元素
STDataType STTop(ST * pst);
//栈里的元素个数
int STSize(ST * pst);