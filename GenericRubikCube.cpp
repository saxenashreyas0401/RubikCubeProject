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
GenericRubikCube &GenericRubikCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::Lp:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::Rp:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::Up:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::Dp:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::Fp:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::Bp:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
    }
}
GenericRubikCube &GenericRubikCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::Lp:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::Rp:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::Up:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::Dp:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::Fp:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::Bp:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}
void GenericRubikCube::print() const {
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<GenericRubikCube::MOVE> GenericRubikCube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moves_performed;
    srand(time(0));
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}
