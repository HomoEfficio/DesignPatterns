cmake_minimum_required(VERSION 3.10)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 11)

add_executable(DesignPatterns
        State/c++/StatePattern.cpp
        Strategy/c++/StrategyPattern.cpp)
