cmake_minimum_required(VERSION 4.0)
project(HW_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(HW_3 main.c
        BitManipulation/MyBitManipulation.c
        Myfloat/Myfloat.c
        MyIntegers/MyIntegers.c
)


