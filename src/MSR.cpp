#include "MSR.hpp"



// I DON'T KNOW WHY IT CREATES PROBLEMS
/*
template <size_t N>
void MSR<N>::CompressGraphMat(int (*gmat)[N]){
    this->values = {};
    this->bindCol = {};

    // COPY DIAGONAL
    for(int ij = 0; ij<size; ij++){
        this->values.push_back(gmat[ij][ij]);
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
            if(gmat[i][j] == 0){
                continue;
            }

            int idxValue = this->values.size();
            this->values.push_back(gmat[i][j]);
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
*/

template <size_t N>
void MSR<N>::CompressGraphFromFile()
{
    // Function for the future
}