#include <SeqList.h>
#include <Contact.h>

//初始化
void Contact_Init(Contact *con)
{
  //调用顺序表的初始化
  SLInit(con);//指向顺序表
}
//销毁
void Contact_Destroy(Contact *con)
{
  SLDestroy(con);
}
//添加
void Contact_Add(Contact *con)
{
  //将信息输入到结构体中
  peoInfo info;

  printf("请输入联系人姓名\n");
  scanf("%s",info.name);

  printf("请输入联系人性别\n");
  scanf("%s",info.gender);

  printf("请输入联系人年龄\n");
  scanf("%d",&info.age);

  printf("请输入联系人电话\n");
  scanf("%s",info.tel);

  printf("请输入联系人住址\n");
  scanf("%s",info.addr);

  //使用顺序表的功能，尾插
  SLPushFront(con,info);
}
//查找姓名
int FindByname(Contact *con,char name[])
{
  for (int i = 0;i<con->size;i++)
  {
    if (strcmp(con->arr[i].name,name) == 0)
    {
      //找到了,返回这个名字的下标
      return i;
    }
  }
  //  出循环，没找到
  return -1;
}
//删除
void Contact_Del(Contact *con)
{
  again:
  //删除一个信息需要先看是否存在
  //并获取这个人在哪
  //通过peoinfo里的姓名来判断是否存在
  char arr[20] = {0};
  printf("请输入要删除的人的名字:");
  scanf("%s",arr);
  //检查是否存在这个人
  int r = FindByname(con,arr);

  if (r != -1)
  {
    //存在
    SLErase(con,r);
  }
  else
  {
    printf("此人不存在\n");
    printf("要重新输入吗？如果要，请输入 1，不要输入 0\n");
    int x = 0;
    scanf("%d",&x);
    if (x == 1)
    {
      goto again;
    }
    else if (x == 0)
      return;
  }
}
void Contact_Show( Contact *con)
{
  //打印数据，姓名，性别，年龄，电话，住址
  printf("%s %s %s %s %s\n","姓名","性别","年龄","电话","住址");
  for (int i = 0;i<con->size;i++)
  {
    printf("%3s %3s %3d %3s %3s\n",
          con->arr[i].name,
          con->arr[i].gender,
          con->arr[i].age,
          con->arr[i].tel,
          con->arr[i].addr
    );
  }
}
//修改
void Contact_Modify(Contact * con)
{
  again:
  char name[NAME_MAX];
  printf("请输入要修改的用户姓名:");
  scanf("%s",name);
  int r  = FindByname(con,name);
  if (r < 0)
  {
    printf("要修改的用户不存在\n");
    printf("要重新输入吗？如果要，请输入 1，不要输入 0\n");
    int x = 0;
    scanf("%d",&x);
    if (x == 1)
    {
      goto again;
    }
    else
    return;
  }
  else
  {
    printf("请输入修改后的姓名:");
    scanf("%s",con->arr[r].name);
    printf("\n");

    printf("请输入修改后的性别:");
    scanf("%s",con->arr[r].gender);
    printf("\n");

    printf("请输入修改后的年龄:");
    scanf("%d",&(con->arr[r].age));
    printf("\n");

    printf("请输入修改后的电话:");
    scanf("%s",con->arr[r].tel);
    printf("\n");

    printf("请输入修改后的地址:");
    scanf("%s",con->arr[r].addr);
    printf("\n");
  }
  printf("修改成功\n");
}
//查找
void Contact_Find(Contact *con)
{
  char name[NAME_MAX];
  printf("请输入要查找的用户名名字\n");
  scanf("%s",name);
  int r = FindByname(con,name);
  if (r < 0)
  {
    printf("不存在\n");
    return ;
  }
  else
  {
    printf("%s %s %s %s %s\n","姓名","性别","年龄","电话","住址");
    printf("%3s %3s %3d %3s %3s\n",
          con->arr[r].name,
          con->arr[r].gender,
          con->arr[r].age,
          con->arr[r].tel,
          con->arr[r].addr
          );
  }
}
