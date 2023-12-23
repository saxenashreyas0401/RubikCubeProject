cmake_minimum_required(VERSION 3.27)
project(RubikCubeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubikCubeProject main.cpp
        GenericRubikCube.cpp
        GenericRubikCube.h
        RubikCube3DArray.cpp
        RubikCube1DArray.cpp
        DFSSOLVER.h)
