//
// Created by Shreyas on 25-12-2023.
//

#ifndef RUBIKCUBEPROJECT_CORNERPATTERNDATABASE_H
#define RUBIKCUBEPROJECT_CORNERPATTERNDATABASE_H
#include "GenericRubikCube.h"
#include "PermutationIndexer.h"
#include "PatternDatabase.h"
class CornerPatternDatabase : public PatternDatabase {
    typedef GenericRubikCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const GenericRubikCube& cube) const;
};


#endif //RUBIKCUBEPROJECT_CORNERPATTERNDATABASE_H
