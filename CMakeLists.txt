cmake_minimum_required(VERSION 3.27)
project(RubikCubeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubikCubeProject main.cpp
        GenericRubikCube.cpp
        GenericRubikCube.h
        RubikCube3DArray.cpp
        DFSSOLVER.h
        IDDFSSOLVER.h
        IDASTARSOLVER.h
        NibbleArray.cpp
        NibbleArray.h
        PatternDatabase.cpp
        PatternDatabase.h
        math.cpp
        math.h
        PermutationIndexer.h
        RubikCubeBitboard.cpp
        CornerPatternDatabase.cpp
        CornerPatternDatabase.h
        CornerDBMaker.cpp
        CornerDBMaker.h
)
