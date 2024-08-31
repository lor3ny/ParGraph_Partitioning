#include "MSR.hpp"



// I DON'T KNOW WHY IT CREATES PROBLEMS
void MSR::CompressGraphMat(int* gmat){
    this->values = {};
    this->bindCol = {};

    // COPY DIAGONAL
    for(int ij = 0; ij<size; ij++){
        this->values.push_back(gmat[ij+ij*size]);
    }
    this->values.push_back(-1);

    vector<int> columns = {};
    for(int i = 0; i<size; i++){
        bool firstFound = false;
        bool zeroRow = true;
        for(int j = 0; j<size; j++){
            if(i == j){
                continue;
            }
            if(gmat[j+i*size] == 0){
                continue;
            }

            int idxValue = this->values.size();
            this->values.push_back(gmat[j+i*size]);
            columns.push_back(j);
            if(!firstFound)
                this->bindCol.push_back(idxValue);

            firstFound = true;
            zeroRow = false;
        }
        if(zeroRow){
            this->bindCol.push_back(-1);
        }
    }
    this->bindCol.push_back(this->values.size());

    for(int& column : columns){
        this->bindCol.push_back(column);
    }

}


void MSR::CompressGraphFromFile()
{
    // Function for the future
}