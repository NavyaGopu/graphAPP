cmake_minimum_required(VERSION 3.7)
project(graphApp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        graphApp/BarGraph.cpp
        graphApp/BarGraph.h
        graphApp/Graph.cpp
        graphApp/Graph.h
        graphApp/graphApp.cpp
        graphApp/LineGraph.cpp
        graphApp/LineGraph.h
        graphApp/Point.cpp
        graphApp/Point.h
        graphApp/PointGraph.cpp
        graphApp/PointGraph.h
        graphApp/stdafx.cpp
        graphApp/stdafx.h
        graphApp/targetver.h)

add_executable(graphApp ${SOURCE_FILES})