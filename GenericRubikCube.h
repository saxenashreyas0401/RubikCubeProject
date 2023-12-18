//
// Created by Shreyas on 18-12-2023.
//

#ifndef RUBIKCUBEPROJECT_GENERICRUBIKCUBE_H
#define RUBIKCUBEPROJECT_GENERICRUBIKCUBE_H

#include<bits/stdc++.h>
using namespace std;

class GenericRubikCube {
public:
    enum class Face{
        UP,
        LEFT,
        RIGHT,
        BACK,
        DOWN,
        FRONT
    };
    enum class COLOR{
        RED,
        YELLOW,
        WHITE,
        GREEN,
        ORANGE,
        BLUE
    };
    enum class MOVE{
        L, Lp, L2,
        R, Rp, R2,
        U, Up, U2,
        D, Dp, D2,
        F, Fp, F2,
        B, Bp, B2
    };
    virtual bool isSolved() const = 0;
    void print() const;
    vector<MOVE> RandomeShuffle(unsigned int times);


};


#endif //RUBIKCUBEPROJECT_GENERICRUBIKCUBE_H
