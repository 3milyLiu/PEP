cmake_minimum_required(VERSION 3.12)
project(assignment20182_3milyLiu)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment20182_3milyLiu
        Item.h
        MapOfItems.h
        MapOfItemsTest.cpp
        Stack.h
        StringConstruction.h
        TestStack.cpp
        TestStringCons.cpp)
