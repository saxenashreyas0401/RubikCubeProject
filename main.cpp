#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
#include "DFSSOLVER.h"
#include "IDDFSSOLVER.h"
#include "IDASTARSOLVER.h"
using namespace std;
int main() {
    RubikCube3DArray cube;
    vector<GenericRubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    for(auto move:shuffle_moves)cout<<cube.getMove(move)<<" ";
    cout<<"\n";
    cube.print();
    cout<<"\n";
    IDASTARSOLVER<RubikCube3DArray,Hash3d> idastarsolver(cube);
    vector<GenericRubikCube::MOVE> solving_moves = idastarsolver.solve();
    for(auto move:solving_moves)cout<<cube.getMove(move)<<" ";
    return 0;
}
