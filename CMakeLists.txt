cmake_minimum_required(VERSION 4.1)
project(DataStructure_Employment C)

set(CMAKE_C_STANDARD 11)

include_directories(C_Data_Structures/1.SeqList)

add_executable(DataStructure_Employment
        C_Data_Structures/1.SeqList/SeqList.c
        C_Data_Structures/1.SeqList/SeqList.h
        C_Data_Structures/1.SeqList/test.c
        C_Data_Structures/1.SeqList/Contact.c
        C_Data_Structures/1.SeqList/Contact.h)
# 添加自定义目标
add_custom_target(open_terminal
        COMMAND open -a Terminal ./
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)