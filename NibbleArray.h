//
// Created by Shreyas on 24-12-2023.
//

#ifndef RUBIKCUBEPROJECT_NIBBLEARRAY_H
#define RUBIKCUBEPROJECT_NIBBLEARRAY_H
#include<bits/stdc++.h>
using namespace std;

class NibbleArray {
    size_t size;
    vector<uint8_t> arr;
public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t get(const size_t pos) const;

    void set(const size_t pos, const uint8_t val);
};


#endif //RUBIKCUBEPROJECT_NIBBLEARRAY_H
