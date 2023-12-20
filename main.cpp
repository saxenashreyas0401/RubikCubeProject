#include <bits/stdc++.h>
#include "RubikCube3DArray.cpp"
using namespace std;

int main() {
    RubikCube3DArray obj3DArray;
    vector<GenericRubikCube::MOVE> movesinshuffle = obj3DArray.randomShuffleCube(3);
    for(auto move:movesinshuffle)
    {
        cout<<obj3DArray.getMove(move)<<" ";
    }
    cout<<"\n";
    obj3DArray.print();
    return 0;
}
