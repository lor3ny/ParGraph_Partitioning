#include <vector>
#include "Coarser.hpp"



using namespace std;

CSR Coarser::CoarsCSR(){

    vector<int> valuePointers;
    int startIdxCounter = 0;
    int dim = 0;
    CSR newCSR;

    cout << "Coarsening started" << endl;

    for(int i = 0; i<(*this->csr_pt).GetSize(); i++){
        // Node alreade merged, skip
        if(coarNodesBits[i]){
            continue;
        }
        int rowStart = (*this->csr_pt).iIdx[i];
        int rowEnd = (*this->csr_pt).iIdx[i+1];

        // The node doesn't have out edges
        if(rowStart == -1){
            newCSR.iIdx.push_back(-1);
            continue;
        }
        if(rowEnd == -1){
            rowEnd = (*this->csr_pt).iIdx[i+2];
        }

        cout << i << " : ";
        vector<int> masterEdges = {};
        // ------- TRIVIAL HEURISTIC --------
        int masterNode = i;
        int selNode = -1;
        newCSR.iIdx.push_back(startIdxCounter);

        //Iterate connections and select the node by the column, the value are always 1 so we don't have to check it
        for(int j = rowStart; j < rowEnd; j++){
            int value = (*this->csr_pt).values[j];
            int column = (*this->csr_pt).jCoeff[j];

            if(coarNodesBits[column]){
                continue;
            }

            cout << " " << column << " ";
            
            bool hasBeenSelected = false;
            if(selNode == -1){
                masterNode = i;
                selNode = (*this->csr_pt).jCoeff[j];
                hasBeenSelected = true;
            }

            // Insert only whether the node is not been selected
            if(!hasBeenSelected){
                newCSR.values.push_back(value);
                newCSR.jCoeff.push_back(column);
                masterEdges.push_back(column);
                startIdxCounter += 1;
            }
        }
        // It shouldn't arrive there
        if(selNode == -1){
            cout << "ALREADY SELECTED EDGES" <<endl;
            continue;
            // No merging is possible;
        } else {
            cout << " -- SELECTED: " << selNode <<" --";
        }
        // ------- TRIVIAL HEURISTIC --------
        
        // Not possible in our configuration
        if(selNode == masterNode){
            newCSR.values[selNode] = 1;
            cout << endl;
            break;
        }

        int selRowStart = (*this->csr_pt).iIdx[selNode];
        int selRowEnd = (*this->csr_pt).iIdx[selNode+1];
        
        // This is possible only with directed (*this->csr_pt)s
        bool noMergingNeeded = false;
        if(selRowStart == -1){
            // Is an empty row, no values/cols merging needed :)
            noMergingNeeded = true;
        }
        if(selRowEnd == -1){
            selRowEnd = (*this->csr_pt).jCoeff[i+2];
        }
        // Take all the values and all the columns of thew selected nodes
        for(int j = selRowStart; j < selRowEnd; j++){
            // FIND A WAY TO FIGURE HOW TO RESPECT VALUE ORDER AND COLUMN ORDER WHEN YOU MERGE THE VALUES/COLS OF THE TWO MERGING NODES
            // Maybe is not needed to respect values order, in that case we have to check only if the value is already been inserted
            int value = (*this->csr_pt).values[j];
            int column = (*this->csr_pt).jCoeff[j];
            
            // Check if the column is already there
            if(column == masterNode){
                continue;
            }
            bool thereIs = false;
            for(int& col : masterEdges){
                if(col == column){
                    thereIs = true;
                    break;
                }
            }
            if(thereIs){
                continue;
            }

            cout << " " << column << " ";

            newCSR.values.push_back(value);
            newCSR.jCoeff.push_back(column);
            startIdxCounter += 1;
        }
        coarNodesBits[masterNode] = 1;
        coarNodesBits[selNode] = 1;
        mergedNodes.push_back(vector{masterNode, selNode});
        dim += 1;
        cout << endl;
    }
    newCSR.iIdx.push_back(newCSR.values.size());
    newCSR.SetSize(dim);
    cout << endl;

    return newCSR;
}


void Coarser::UncoarsCSR(){
    // Let's see
}

