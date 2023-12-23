//
// Created by Shreyas on 23-12-2023.
//

#ifndef RUBIKCUBEPROJECT_IDDFSSOLVER_H
#define RUBIKCUBEPROJECT_IDDFSSOLVER_H
#include<bits/stdc++.h>
#include "GenericRubikCube.h"
#include "DFSSOLVER.h"
template<typename T, typename H>
class IDDFSSOLVER{
private:
    vector<GenericRubikCube::MOVE> moves;
    int max_search_depth;
public:
    T rubiksCube;
    IDDFSSOLVER(T rc, int md)
    {
        rubiksCube = rc;
        max_search_depth = md;
    }
    vector<GenericRubikCube::MOVE> solve()
    {
        for(int i = 1;i<=max_search_depth;i++)
        {
            DFSSOLVER<T,H> dfssolver(rubiksCube,i);
            moves = dfssolver.solve();
            if(dfssolver.rubiksCube.isSolved())return moves;
        }
    }
};
#endif //RUBIKCUBEPROJECT_IDDFSSOLVER_H
