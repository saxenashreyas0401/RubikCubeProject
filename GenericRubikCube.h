//
// Created by Shreyas on 18-12-2023.
//

#ifndef RUBIKCUBEPROJECT_GENERICRUBIKCUBE_H
#define RUBIKCUBEPROJECT_GENERICRUBIKCUBE_H

#include<bits/stdc++.h>
using namespace std;

class GenericRubikCube {
public:
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE{
        L, Lp, L2,
        R, Rp, R2,
        U, Up, U2,
        D, Dp, D2,
        F, Fp, F2,
        B, Bp, B2
    };
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const = 0;

    static string getMove(MOVE ind);

    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);

    GenericRubikCube &move(MOVE ind);

    GenericRubikCube &invert(MOVE ind);

    virtual GenericRubikCube &f() = 0;

    virtual GenericRubikCube &fPrime() = 0;

    virtual GenericRubikCube &f2() = 0;

    virtual GenericRubikCube &u() = 0;

    virtual GenericRubikCube &uPrime() = 0;

    virtual GenericRubikCube &u2() = 0;

    virtual GenericRubikCube &l() = 0;

    virtual GenericRubikCube &lPrime() = 0;

    virtual GenericRubikCube &l2() = 0;

    virtual GenericRubikCube &r() = 0;

    virtual GenericRubikCube &d() = 0;

    virtual GenericRubikCube &dPrime() = 0;

    virtual GenericRubikCube &d2() = 0;

    virtual GenericRubikCube &rPrime() = 0;

    virtual GenericRubikCube &r2() = 0;

    virtual GenericRubikCube &b() = 0;

    virtual GenericRubikCube &bPrime() = 0;

    virtual GenericRubikCube &b2() = 0;




};


#endif //RUBIKCUBEPROJECT_GENERICRUBIKCUBE_H
