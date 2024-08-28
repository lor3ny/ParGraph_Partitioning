#pragma once

#include <vector>

using namespace std;

class Coarser {


private:

    int size;
    // When the coarser is used, it use this structure to take trake which node is already coarsed
    vector<char> coarNodesBits;
    // element mergedNodes[i] correspond to all the nodes merged in node i
    vector<vector<int>> mergedNodes;

public:

    Coarser(int size){
        this->size = size;
        coarNodesBits[size] = 0;
        mergedNodes[size] = {};
    }

    void CoarsMSR(){
        for(int i = 0; i<size; i++){

            if(coarNodesBits[i]){
                // Node alreade merged, skip
                continue;
            }


            // COARSENING


        }
    }

    // This function express the heuristic used by the coarser to choose which nodes coarse
    void SelectTheNode(){

    }

    void UncoarsMSR(){

    }

};