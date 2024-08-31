#pragma once

#include <vector>
#include "MSR.hpp"

using namespace std;


class Coarser {


private:

    int size;
    // When the coarser is used, it use this structure to take trake which node is already coarsed
    vector<int> coarNodesBits;
    // element mergedNodes[i] correspond to all the nodes merged in node i
    vector<vector<int>> mergedNodes;

public:

    Coarser(int size){
        this->size = size;
        coarNodesBits[size] = 0;
    }

    MSR CoarsMSR(MSR graph);

    void UncoarsMSR();

};