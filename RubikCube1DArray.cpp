//
// Created by Shreyas on 20-12-2023.
//
#include "GenericRubikCube.h"

class RubikCube1DArray : public GenericRubikCube{
private:
    void rotateFace(int ind)
    {
        int st = ind * 9;
        char temp[3][3] = {};
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)temp[i][j] = cube[st + 3*i + j];
        }
        for(int i = 0 ; i<3; i++)
        {
            cube[st + i] = temp[2-i][0];
            cube[st + 2 + 3*i] = temp[0][i];
            cube[st + 6 + i] = temp[2-i][2];
            cube[st + 3*i] = temp[2][i];
        }
    }
public:
    char cube[54];
    RubikCube1DArray()
    {
        for(int i = 0; i<6; i++)
        {
            for(int j = 0; j<3; j++)
            {
                for(int k = 0; k<3; k++)
                {
                    cube[9*i + 3*j + k] = getColorLetter(COLOR(i));
                }
            }
        }
    }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override{
        char color = cube[9*int(face) + 3*row + col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }
    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[9*i + 3*j + k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

};
