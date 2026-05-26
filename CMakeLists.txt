cmake_minimum_required(VERSION 3.28)
project(DataStructure_Employment C)

set(CMAKE_C_STANDARD 11)

# ==========================================
# 项目 1：顺序表 (SeqList)
# ==========================================
add_executable(SeqList_Run
        C_Data_Structures/1.SeqList/test.c
        C_Data_Structures/1.SeqList/SeqList.c
        C_Data_Structures/1.SeqList/SeqList.h
        C_Data_Structures/1.SeqList/Contact.c
        C_Data_Structures/1.SeqList/Contact.h
)
target_include_directories(SeqList_Run PRIVATE C_Data_Structures/1.SeqList)


# ==========================================
# 项目 2：单链表 (SList)
# ==========================================
add_executable(SList_Run
        C_Data_Structures/2.SList/test.c
        C_Data_Structures/2.SList/SList.c
        C_Data_Structures/2.SList/SList.h
)
target_include_directories(SList_Run PRIVATE C_Data_Structures/2.SList)

# ==========================================
# 项目 3：带头双向循环链表 (DList)
# ==========================================
add_executable(List_Run
        C_Data_Structures/3.List/List.c
        C_Data_Structures/3.List/List.h
        C_Data_Structures/3.List/test.c
)
target_include_directories(List_Run PRIVATE C_Data_Structures/3.List)

# ==========================================
# 项目 4：栈 (Stack)
# ==========================================
add_executable(Stack_Run
        C_Data_Structures/4.Stack/Stack.c
        C_Data_Structures/4.Stack/Stack.h
        C_Data_Structures/4.Stack/Test.c
)
target_include_directories(Stack_Run PRIVATE C_Data_Structures/4.Stack)

# ==========================================
# 项目 5：队列 (Queue)
# ==========================================
add_executable(Queue_Run
        C_Data_Structures/5.Queue/queue.c
        C_Data_Structures/5.Queue/queue.h
        C_Data_Structures/5.Queue/test.c
)
target_include_directories(Queue_Run PRIVATE C_Data_Structures/5.Queue)

# ==========================================
# 项目 6：二叉树 (Binary_Tree)
# ==========================================
add_executable(Tree_Run
        C_Data_Structures/6.Binary_Tree/test.c
        C_Data_Structures/6.Binary_Tree/Heap.c
        C_Data_Structures/6.Binary_Tree/Heap.h
        C_Data_Structures/6.Binary_Tree/queue.c
        C_Data_Structures/6.Binary_Tree/queue.h
)
target_include_directories(Tree_Run PRIVATE C_Data_Structures/6.Binary_Tree)

# ==========================================
# 项目 7：排序 (Sort)
# ==========================================
add_executable(Sort_Run
        C_Data_Structures/7.Sort/Sort.c
        C_Data_Structures/7.Sort/test.c
        C_Data_Structures/7.Sort/Sort.h
)
target_include_directories(Sort_Run PRIVATE C_Data_Structures/7.Sort)
