#pragma once

#include <stdio.h>
#include <assert.h>
//通讯录的头文件

//personInfo的数据内容，姓名，性别，年龄，手机号，住址
//现在将通讯录成员的信息放入顺序表中
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL 20
#define ADDR_MAX 100
//定义通讯录成员的数据
typedef struct personInfo
{
  char name[NAME_MAX];//20
  char gender[GENDER_MAX];//10
  int age;
  char tel[TEL];//20
  char addr[ADDR_MAX];//地址100
}peoInfo;//将顺序表的结构体元素的命名为peoInfo

//对通讯录进行一系列操作，其实就是对顺序表进行操作
//所以把顺序表重命名改成通讯录

//因为 SL 没有声明，所以需要前置声明
struct SeqList;
typedef struct SeqList Contact;//将顺序表重命名为通讯录名字

//通讯录的初始化
void Contact_Init(Contact * con);

//通讯录的销毁
void Contact_Destroy(Contact * con);

//通讯录的添加数据
void Contact_Add(Contact * con);

//通讯录的删除数据
void Contact_Del(Contact *con);

//通讯录的修改
void Contact_Modify(Contact * con);

//通讯录的查找
void Contact_Find(Contact * con);

//通讯录的显示数据
void Contact_Show(Contact * con);
