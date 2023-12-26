#include <bits/stdc++.h>
//#include "RubikCubeBitboard.cpp"
#include "IDASTARSOLVER.h"
#include "CornerPatternDatabase.h"
#include "CornerDBMaker.h"
using namespace std;
int main() {
    string fileName = "C:\\\\Users\\\\Shreyas\\\\CLionProjects\\\\RubikCubeProject\\\\cornerDepth5V2.txt";
    //CornerDBMaker dbMaker(fileName, 0x99);
    //dbMaker.bfsAndStore();
    RubiksCubeBitboard cube;
    vector<GenericRubikCube::MOVE> shffule_moves = cube.randomShuffleCube(9);
    for(auto move:shffule_moves)cout<<cube.getMove(move)<<" ";
    cout<<"\n";
    cube.print();
    IDASTARSOLVER<RubiksCubeBitboard,HashBitboard> idastarsolver(cube, fileName);
    vector<GenericRubikCube::MOVE> solving_moves = idastarsolver.solve();
    for(auto move:solving_moves)cout<<cube.getMove(move)<<" ";
    return 0;
}
