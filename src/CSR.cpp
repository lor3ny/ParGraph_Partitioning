#include "CSR.hpp"


void CSR::CompressGraphMat(int* gmat){
    this->values = {};
    this->jCoeff = {};

    for(int i = 0; i<size; i++){
        bool firstFound = false;
        bool zeroRow = true;

        for(int j = 0; j<size; j++){
            if(gmat[j+i*size] == 0){
                continue;
            }

            int idxValue = this->values.size();
            this->values.push_back(gmat[j+i*size]);
            this->jCoeff.push_back(j);
            if(!firstFound)
                this->iIdx.push_back(idxValue);

            firstFound = true;
            zeroRow = false;
        }
        if(zeroRow){
            this->iIdx.push_back(-1);
        }
    }
    this->iIdx.push_back(values.size());

}

// THE MAT IS ALREADY INITIALIZED WIT ALL ZEROS
void CSR::CSRtoMat(int* mat, int n){
    if(n != this->size){
        cerr << "Matrice Bad Allocation: verify the size of the allocated matrix. ABORT" << endl;\
        return;
    }

    for(int i = 0; i<this->GetSize(); i++){
        int rowStart = this->iIdx[i];
        int rowEnd = this->iIdx[i+1];
        if(rowStart == -1){
            continue;
        }
        if(rowEnd == -1){
            rowEnd = this->iIdx[i+2];
        }

        for(int j = rowStart; j < rowEnd; j++){
            mat[i*this->GetSize() + this->jCoeff[j]] = this->values[j];
        }
    }

}


void CSR::CompressGraphFromFile()
{
    // Function for the future
}