cmake_minimum_required(VERSION 3.26)
project(OstGraph)

set(CMAKE_CXX_STANDARD 23)
set(TEST_MODE true)

if (TEST_MODE)
    add_executable(OstGraph test.cpp
            Graph.h
            Graph.cpp
            Kruskal.h
            Kruskal.cpp
            OstBase.h
            Prim.h
            Prim.cpp)
else ()
    add_executable(OstGraph main.cpp
            Graph.h
            Graph.cpp
            Kruskal.h
            Kruskal.cpp
            OstBase.h
            Prim.h
            Prim.cpp)
endif ()
