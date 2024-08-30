#pragma once

#include <vector>
#include <MSR.hpp>

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

    template<int N>
    void CoarsMSR(MSR<N> graph){

        for(int i = 0; i<msr.GetSize(); i++){


            int n = N;
            MSR<n> newMSR;
            newMSR.values[n+1] = {0};
            newMSR.bindCol[n+1] = {0};

            // Node alreade merged, skip
            if(coarNodesBits[i]){
                continue;
            }

            int rowStart = graph.bindCol[i];
            int rowEnd = graph.bindCol[i+1];

            // The node doesn't have out edges
            if(rowStart == -1){
                newMSR.bindCol[i] = -1;
                continue;
            }
            if(rowEnd == -1){
                rowEnd = graph.bindCol[i+2];
            }

            //Iterate connections and select the node by the column, the value are always 1 so we don't have to check it
            vector<vector<int>> groups;
            for(int j = rowStart; j < rowEnd; j++){
                if(coarNodesBits[j]){
                    continue;
                }

                // ------- TRIVIAL HEURISTIC -------- 
                int masterNode = i;
                int selectedNode = msr.bindCol[j]

                // Not possible in our configuration
                if(selectedNode == masterNode){
                    newMSR.values[selectedNode] = 1;
                    break;
                }

                coarNodesBits[masterNode] = 1;
                coarNodesBits[selectedNode] = 1;
                break;
                // ------- TRIVIAL HEURISTIC --------
            }

            // once the groups are builded, build the msr
            for(auto& group : groups){
                int chiefNode = group[0];
                for(int k = 0; k < group.size(); k++){

                    graph.

                }
            }

        }

        for(int i = 0; i<size; i++){

            // COARSENING

            graph.


            coarNodesBits[i] = 1;

        }
    }


    void UncoarsMSR(){
        // Let's see
    }

};