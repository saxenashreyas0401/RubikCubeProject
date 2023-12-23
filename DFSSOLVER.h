//
// Created by Shreyas on 23-12-2023.
//

#ifndef RUBIKCUBEPROJECT_DFSSOLVER_H
#define RUBIKCUBEPROJECT_DFSSOLVER_H

#include<bits/stdc++.h>
#include "GenericRubikCube.h"

template<typename T, typename H>
class DFSSOLVER{
private:
    vector<GenericRubikCube::MOVE> moves;
    int max_search_depth;
    int k = 0;
    void dfs(int depth)
    {
        if(k==1)return;
        if(rubiksCube.isSolved())
        {
            //for(auto move:moves)cout<<rubiksCube.getMove(move)<<" ";
            k = 1;
            return;
        }
        for(int i=0;i<18;i++)
        {
            auto cur_move = GenericRubikCube::MOVE(i);
            rubiksCube.move(cur_move);
            moves.push_back(cur_move);
            if(depth<max_search_depth)dfs(depth+1);
            if(k==1)return;
            rubiksCube.invert(cur_move);
            moves.pop_back();
        }
    }
public:
    T rubiksCube;
    DFSSOLVER(T rc, int md)
    {
        rubiksCube = rc;
        max_search_depth = md;
    }
    vector<GenericRubikCube::MOVE> solve()
    {
        dfs(0);
        return moves;
    }
};

#endif //RUBIKCUBEPROJECT_DFSSOLVER_H
