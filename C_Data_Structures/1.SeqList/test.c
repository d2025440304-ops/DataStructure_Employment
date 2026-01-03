#include "SeqList.h"//包含头文件，正常使用头文件里所声明的函数
#include "Contact.h"
//此文件是测试文件，用来测试顺序表的功能实现是否正常
//测试初始化功能
//
// void SLTest01()
// {
//     SL sl;
//
//     SLInit(&sl);//初始化
//   //测试尾插
//     SLPushBack(&sl,1);
//     SLPushBack(&sl,2);
//     SLPushBack(&sl,3);
//     SLPushBack(&sl,4);
//     SLPushBack(&sl,5);
//     SLPrint(sl);//打印
//
//   //测试头插
//     SLPushFront(&sl,6);
//     SLPushFront(&sl,7);
//     SLPrint(sl);//打印
// //
// //   // //测量头删
// //   //   SLPopFront(&sl);
// //   // SLPrint(sl);
// //   //   SLPopFront(&sl);
// //   // SLPrint(sl);
// //   //   SLPopFront(&sl);
// //   // SLPrint(sl);
// //   //   SLPopFront(&sl);
// //   // SLPrint(sl);
// //   //   SLPopFront(&sl);
// //   // SLPrint(sl);
// //
// //   //测量尾删
// //     SLPopBack(&sl);
// //   SLPrint(sl);
// //   SLPopBack(&sl);
// //   SLPrint(sl);
// //   SLPopBack(&sl);
// //   SLPrint(sl);
// //   SLPopBack(&sl);
// //   SLPrint(sl);
// //   SLPopBack(&sl);
//   SLPrint(sl);
//   SLDestroy(&sl);//销毁
// }


// void SLTest02()
// {
//   SL sl;
//   SLInit(&sl);
//   //测试尾插
//   SLPushBack(&sl,1);
//   SLPushBack(&sl,2);
//   SLPushBack(&sl,3);
//   SLPushBack(&sl,4);
//   SLPushBack(&sl,5);
//   SLPrint(sl);//打印
// //测试指定位置插入
//   // SLInsert(&sl,3,99);//1,2,3,99,4,5中间插入
//   // SLPrint(sl);//打印
//   // SLInsert(&sl,0,88);//88,1,2,3,99,4,5头插
//   // SLPrint(sl);//打印
//   // SLInsert(&sl,5,10);//尾插
//   // SLPrint(sl);//打印
//
//   //测试指定位置的删除
//   SLErase(&sl,2);
//   SLPrint(sl);
//   //销毁
//   SLDestroy(&sl);
// }


// //通讯录功能的测试
// void ContactTest01()
// {
//   Contact con;
//   //初始化
//   Contact_Init(&con);
//   //添加联系人数据
//   Contact_Add(&con);
//   Contact_Add(&con);
//   //显示联系人
//   Contact_Show(&con);
//   //删除某人信息
//   Contact_Del(&con);
//   Contact_Show(&con);
//   //修改某人信息
//   Contact_Modify(&con);
//   Contact_Show(&con);
//   Contact_Find(&con);
//
//   //销毁
//   Contact_Destroy(&con);
// }
//提示信息，菜单
void menu()
{
  printf("********************通讯录***************************\n");
  printf("********1.添加联系人******* 2.删除联系人****************\n");
  printf("********3.查找联系人********4.修改联系人*********************\n");
  printf("********5.展示联系人********0.退出通讯录********************\n");
  printf("*****************************************************\n");
  printf("*****************************************************\n");
}

enum Option
{
  EXIT,
  ADD,
  DEL,
  FIND,
  MODIFY,
  SHOW
};

int main()
{
  Contact con;
  Contact_Init(&con);
  int input = 0;
  do
  {
    menu();
    printf("请输入你所要进行的操作\n");
    scanf("%d",&input);
    switch(input)
    {
    case ADD:
      Contact_Add(&con);
      break;
    case DEL:
      Contact_Del(&con);
      break;
    case MODIFY:
      Contact_Modify(&con);
      break;
    case FIND:
      Contact_Find(&con);
      break;
    case SHOW:
      Contact_Show(&con);
      break;
    case EXIT:
      break;
    default:
      printf("请输入正确的选项\n");
      break;
    }
  } while (input);

    return 0;
}
