cmake_minimum_required(VERSION 3.26)
project(OstGraph)

set(CMAKE_CXX_STANDARD 23)

add_executable(OstGraph main.cpp
        Graph.h
        Graph.cpp
        Kruskal.h
        Kruskal.cpp
        OstBase.h
        Prim.h
        Prim.cpp)
