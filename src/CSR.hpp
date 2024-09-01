#pragma once

#include <vector>
#include <iostream>


using namespace std;


class CSR {


private:
    int size = -1;

public:

    vector<int> values; // the first NODES_COUNT values are the diagonal, the others are the non-zero values row-wise
    vector<int> jCoeff; //the first NODES_COUNT values are the start of the row in the values array, the others are the column values
    vector<int> iIdx; //row start index on jcoeff and values

    CSR(){
        this->size = 0;
        values = {};
        jCoeff = {};
        iIdx = {};
    }

    CSR(int N){
        this->size = N;
        values = {};
        jCoeff = {};
        iIdx = {};
    }

    CSR(int* gmat, int N){
        this->size = N;
        CompressGraphMat(gmat);
    }

    ~CSR() { }

    inline int GetSize(){ return this->size; }

    inline void SetSize(int n){ this->size = n; }

    inline int BytesSize() const {
        return values.size()*4 + jCoeff.size()*4 + iIdx.size() + 4;
    }

    inline void PrintCSR() const {
        cout << "CSR N=" << this->size << endl;
        cout << "Values: ";
        for(int v : this->values)
            cout << v << " ";
        cout << endl;
        cout << "Columns: ";
        for(int b : this->jCoeff)
            cout << b << " ";
        cout << endl;
        cout << "Start idx: ";
        for(int b : this->iIdx)
            cout << b << " ";
        cout << endl;
    }

        // THE MAT IS ALREADY INITIALIZED WIT ALL ZEROS
    void CSRtoMat(int* mat, int n);

    void CompressGraphMat(int* gmat);

    void CompressGraphFromFile();

};