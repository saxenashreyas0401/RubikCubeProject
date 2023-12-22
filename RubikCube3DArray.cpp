//
// Created by Shreyas on 19-12-2023.
//
#include "GenericRubikCube.h"

class RubikCube3DArray : public GenericRubikCube{
private:
    void rotateFace(int ind)
    {
        char temp[3][3]={};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp[i][j] = cube[ind][i][j];
            }
        }
        for(int i=0;i<3;i++)cube[ind][0][i] = temp[2-i][0];
        for(int i=0;i<3;i++)cube[ind][i][2] = temp[0][i];
        for(int i=0;i<3;i++)cube[ind][2][i] = temp[2-i][2];
        for(int i=0;i<3;i++)cube[ind][i][0] = temp[2][i];

    }
public:
    char cube[6][3][3];

    RubikCube3DArray(){
        for(int i = 0 ; i < 6; i++)
        {
            for(int j = 0; j<3; j++)
            {
                for(int k = 0; k<3; k++)
                {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }

    }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
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
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    GenericRubikCube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    GenericRubikCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    GenericRubikCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    GenericRubikCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubikCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    GenericRubikCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    GenericRubikCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubikCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    GenericRubikCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

   GenericRubikCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubikCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    GenericRubikCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    GenericRubikCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubikCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    GenericRubikCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    GenericRubikCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    GenericRubikCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    GenericRubikCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubikCube3DArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubikCube3DArray &operator=(const RubikCube3DArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};
struct Hash3d {
    size_t operator()(const RubikCube3DArray &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};
