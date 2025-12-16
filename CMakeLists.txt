cmake_minimum_required(VERSION 4.1)
project(DataStructure_Employment C)

set(CMAKE_C_STANDARD 11)

include_directories(C_Data_Structures/1.SeqList)

add_executable(DataStructure_Employment
        C_Data_Structures/1.SeqList/SeqList.c
        C_Data_Structures/1.SeqList/SeqList.h
        C_Data_Structures/1.SeqList/test.c)
