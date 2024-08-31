#pragma once

#include <vector>


using namespace std;


class MSR {


private:

    //char coarsedBits[NODES_COUNT] = {0};
    int size;

public:

    vector<int> values; // the first NODES_COUNT values are the diagonal, the others are the non-zero values row-wise
    vector<int> bindCol; //the first NODES_COUNT values are the start of the row in the values array, the others are the column values

    MSR(int N){
        this->size = N;
    }

    MSR(int* gmat, int N){
        this->size = N;
        CompressGraphMat(gmat);
    }

    ~MSR() { }

    inline int GetSize(){ return this->size; }

    inline void SetSize(int n){ this->size = n; }

    inline int BytesSize() const {
        return values.size()*4 + bindCol.size()*4 + 4;
    }

    void CompressGraphMat(int* gmat);

    void CompressGraphFromFile();

};