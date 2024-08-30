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

        vector<int> valuePointers;
        int pointerCounter = 0;
        for(int i = 0; i<graph.GetSize(); i++){


            // DIMENSION AS A TEMPLATE MUST BE REMOVED
            int n = N;
            MSR<N> newMSR;
            // newMSR.values
            // newMSR.bindCol

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

            // ------- TRIVIAL HEURISTIC --------
            int masterNode = i;
            int selectedNode = -1;

            //Iterate connections and select the node by the column, the value are always 1 so we don't have to check it
            bool hasBeenSelected = false;
            for(int j = rowStart; j < rowEnd; j++){
                if(coarNodesBits[j]){
                    continue;
                }
                
                bool thisIsSelected = false;
                if(!hasBeenSelected){
                    masterNode = i;
                    selectedNode = graph.bindCol[j];
                    hasBeenSelected = true;
                    thisIsSelected = true;
                }

                // Insert only whether the node is not been selected
                if(!thisIsSelected){
                    newMSR.values.push_back(graph.values[j]);
                }

            }
            if(selectedNode == -1){
                // No merging is possible;
            }
            // ------- TRIVIAL HEURISTIC --------
            
            // Not possible in our configuration
            if(selectedNode == masterNode){
                newMSR.values[selectedNode] = 1;
                break;
            }
            int selRowStart = graph.bindCol[selectedNode];
            int selRowEnd = graph.bindCol[selectedNode+1];
            
            // This is possible only with directed graphs
            bool noMergingNeeded = false;
            if(selRowStart == -1){
                // Is an empty row, no values/cols merging needed :)
                noMergingNeeded = true;
            }
            if(selRowEnd == -1){
                selRowEnd = graph.bindCol[i+2];
            }
            // Take all the values and all the columns of thew selected nodes
            for(int j = selRowStart; j < selRowEnd; j++){
                
                
                // FIND A WAY TO FIGURE HOW TO RESPECT VALUE ORDER AND COLUMN ORDER WHEN YOU MERGE THE VALUES/COLS OF THE TWO MERGING NODES
                // Maybe is not needed to respect values order, in that case we have to check only if the value is already been inserted
                int value = graph.values[j];
                int column = graph.bindCol[j];
                break;
            }

            pointerCounter += // NUMBER OF VALUES OR COLS THAT THIS NEW ROW IS GOING TO HAVE

            coarNodesBits[masterNode] = 1;
            coarNodesBits[selectedNode] = 1;
        }

        // COPY ALL THE DIAGONAL VALUES (FROM THE END) ON THE VALUE ARRAY DOING A PUSH_FRONT
        
        pointerCounter += // THE FINAL DIMENSION OF THE MSR
        
        // COPY ALL THE POINTERS (FROM THE END) IN THE BINDCOL ARRAY DOING A PUSH_FRONT

    }


    void UncoarsMSR(){
        // Let's see
    }

};