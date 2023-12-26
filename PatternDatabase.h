//
// Created by Shreyas on 25-12-2023.
//

#ifndef RUBIKCUBEPROJECT_PATTERNDATABASE_H
#define RUBIKCUBEPROJECT_PATTERNDATABASE_H
#include<bits/stdc++.h>
#include "NibbleArray.h"
#include "GenericRubikCube.h"
class PatternDatabase {
    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabase();
public:
    PatternDatabase(const size_t size);
//    Testing for init_val
    PatternDatabase(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const GenericRubikCube &cube) const = 0;

    virtual bool setNumMoves(const GenericRubikCube &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const GenericRubikCube &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

};


#endif //RUBIKCUBEPROJECT_PATTERNDATABASE_H
