//
// Created by Shreyas on 26-12-2023.
//

#ifndef RUBIKCUBEPROJECT_CORNERDBMAKER_H
#define RUBIKCUBEPROJECT_CORNERDBMAKER_H
#include "CornerPatternDatabase.h"
#include "RubikCubeBitboard.cpp"
class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};


#endif //RUBIKCUBEPROJECT_CORNERDBMAKER_H
