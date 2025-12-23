cmake_minimum_required(VERSION 3.28)
project(DataStructure_Employment C)

set(CMAKE_C_STANDARD 11)

# ==========================================
# 项目 1：顺序表 (SeqList)
# ==========================================
add_executable(SeqList_Run
        # 注意：路径前面加了子文件夹的名字
        C_Data_Structures/1.SeqList/test.c
        C_Data_Structures/1.SeqList/SeqList.c
        C_Data_Structures/1.SeqList/SeqList.h
        C_Data_Structures/1.SeqList/Contact.c
        C_Data_Structures/1.SeqList/Contact.h
)
# 头文件路径也要更新
target_include_directories(SeqList_Run PRIVATE C_Data_Structures/1.SeqList)


# ==========================================
# 项目 2：单链表 (SList)
# ==========================================
add_executable(SList_Run
        C_Data_Structures/2.SList/test.c
        C_Data_Structures/2.SList/SList.c
        C_Data_Structures/2.SList/SList.h
)
# 头文件路径也要更新
target_include_directories(SList_Run PRIVATE C_Data_Structures/2.SList)