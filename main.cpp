#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
#include "DFSSOLVER.h"
#include "IDDFSSOLVER.h"
#include "IDASTARSOLVER.h"
#include "PatternDatabase.h"
#include "CornerPatternDatabase.h"
using namespace std;
int main() {
    RubikCube3DArray cube;
    CornerPatternDatabase cornerDB;
    cube.print();
    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 5);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cube.randomShuffleCube(1);
//    cube.print();
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 6);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    return 0;
}
