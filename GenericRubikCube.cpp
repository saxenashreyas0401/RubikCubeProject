//
// Created by Shreyas on 18-12-2023.
//
#include "GenericRubikCube.h"

char GenericRubikCube::getColorLetter(COLOR color) {
    switch(color)
    {
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::RED:
            return 'R';
        case COLOR::WHITE:
            return 'W';
        case COLOR::YELLOW:
            return 'Y';
    }

}
string GenericRubikCube::getMove(MOVE ind) {
    switch(ind)
    {
        case MOVE::B:
            return "B";
        case MOVE::B2:
            return "B2";
        case MOVE::Bp:
            return "BPrime";
        case MOVE::D:
            return "D";
        case MOVE::D2:
            return "D2";
        case MOVE::Dp:
            return "DPrime";
        case MOVE::F:
            return "F";
        case MOVE::F2:
            return "F2";
        case MOVE::Fp:
            return "FPrime";
        case MOVE::U:
            return "U";
        case MOVE::U2:
            return "U2";
        case MOVE::Up:
            return "UPrime";
        case MOVE::L:
            return "L";
        case MOVE::L2:
            return "L2";
        case MOVE::Lp:
            return "LPrime";
        case MOVE::R:
            return "R";
        case MOVE::R2:
            return "R2";
        case MOVE::Rp:
            return "RPrime";
    }
}
