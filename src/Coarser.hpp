#pragma once

#include <vector>
#include "CSR.hpp"

using namespace std;


class Coarser {


private:

    int csrSize;
    // When the coarser is used, it use this structure to take trake which node is already coarsed
    vector<int> coarNodesBits;
    // element mergedNodes[i] correspond to all the nodes merged in node i
    vector<vector<int>> mergedNodes;
    CSR* csr_pt;

public:

    Coarser(CSR* csr_pt){
        this->csr_pt = csr_pt;
        this->csrSize = (*csr_pt).GetSize();
        coarNodesBits = vector(this->csrSize, 0);
    }

    CSR CoarsCSR();

    void UncoarsCSR();

};