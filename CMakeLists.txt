cmake_minimum_required(VERSION 3.28)
project(laba3)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba3 main.cpp
        Smartphone.h
        Smartphone.cpp
        Assert.h
        Assert.cpp
        Validator.h
        Validator.cpp
        Application.cpp
        Application.h
)
