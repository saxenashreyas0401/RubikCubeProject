#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
#include "DFSSOLVER.h"
#include "IDDFSSOLVER.h"
using namespace std;
int main() {
    RubikCube3DArray cube;
    vector<GenericRubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    for(auto move:shuffle_moves)cout<<cube.getMove(move)<<" ";
    cout<<"\n";
    cube.print();
    cout<<"\n";
    IDDFSSOLVER<RubikCube3DArray,Hash3d> iddfssolver(cube,6);
    vector<GenericRubikCube::MOVE> solving_moves = iddfssolver.solve();
    for(auto move:solving_moves)cout<<cube.getMove(move)<<" ";
    return 0;
}
