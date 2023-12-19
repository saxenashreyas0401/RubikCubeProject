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
        for(int i = 0 ; i < 3; i++)
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

};
