#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
#include "DFSSOLVER.h"
using namespace std;
int main() {
    RubikCube3DArray cube;
    vector<GenericRubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(4);
    for(auto move:shuffle_moves)cout<<cube.getMove(move)<<" ";
    cout<<"\n";
    cube.print();
    cout<<"\n";
    DFSSOLVER<RubikCube3DArray,Hash3d> dfssolver(cube,4);
    dfssolver.solve();
    return 0;
}
