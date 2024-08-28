#pragma once

#include <vector>


using namespace std;

template <size_t N>
class MSR {


private:

    //char coarsedBits[NODES_COUNT] = {0};
    int size;

public:

    vector<int> values; // the first NODES_COUNT values are the diagonal, the others are the non-zero values row-wise
    vector<int> bindCol; //the first NODES_COUNT values are the start of the row in the values array, the others are the column values

    MSR(){
        this->size = N;
    }


    MSR(int (&gmat)[N][N]){
        this->size = N;
        CompressGraphMat(gmat);
    }

    ~MSR() { }

    inline int GetSize(){ return this->size; }

    inline int BytesSize() const {
        return values.size()*4 + bindCol.size()*4 + 4;
    }

    void CompressGraphMat(int (*gmat)[N]){
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


    void CompressGraphFromFile();

};