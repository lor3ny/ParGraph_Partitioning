#include <iostream>
#include <cstdlib>
#include "MSR.hpp"

#define NODES_COUNT 20
#define MIN_EDGES_COUNT 5


using namespace std;

// ----------------------------------------------------------
// DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG
// ----------------------------------------------------------

bool compareMat(int* a, int* b, int n){
    for(int i = 0; i<NODES_COUNT; i++){
        for(int j = 0; j<NODES_COUNT; j++)
        {
            if(a[j+i*n] != b[j+i*n])  {return false;}
        }
    }
    return true;
}

void PrintGraph(int* g, int size){
    cout << "STARTING GRAPH N=" << size << endl;
    for(int i = 0; i<NODES_COUNT; i++){
        for(int j = 0; j<NODES_COUNT; j++)
        {
            cout << g[j+i*size] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// THE MAT IS ALREADY INITIALIZED WIT ALL ZEROS
void MSRtoMat(MSR& msr, int* mat){

    // PRINT MSR
    cout << "MSR MSR N=" << msr.GetSize() << endl;
    cout << "Values: ";
    for(int& v : msr.values)
        cout << v << " ";
    cout << endl;
    cout << "Bind: ";
    for(int& b : msr.bindCol)
        cout << b << " ";
    cout << endl;
    // PRINT MSR


    // col = i+(n)
    for(int i = 0; i<NODES_COUNT; i++){
        mat[i+i*NODES_COUNT] = msr.values[i];
    }

    for(int i = 0; i<msr.GetSize(); i++){
        int rowStart = msr.bindCol[i];
        int rowEnd = msr.bindCol[i+1];
        if(rowStart == -1){
            continue;
        }
        if(rowEnd == -1){
            rowEnd = msr.bindCol[i+2];
        }

        for(int j = rowStart; j < rowEnd; j++){
            mat[i*msr.GetSize() + msr.bindCol[j]] = msr.values[j];
        }
    }

}

// THE MAT IS ALREADY INITIALIZED WIT ALL ZEROS
void GenerateGraphMat(int* graph, int n, float sparsity){

    for(int i = 0; i<NODES_COUNT; i++){
        for(int j = 0; j<NODES_COUNT; j++)
        {
            // NO SELF-LOOPS CONDITION
            if(i == j){
                continue;
            }

            // UNDIRECTED GRAPH CONDITION
            if(graph[j+i*n] == 1){
                continue;
            }

            float occurrence = (rand() % 100)/100.0f;
            if(occurrence < sparsity){
                graph[i+j*n] = 1;
                graph[j+i*n] = 1; // UNDIRECTED GRAPH CONDITION
            }
        }
    }
    return;
}

// ----------------------------------------------------------
// DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG
// ----------------------------------------------------------


void MSRGraphCoarsening(MSR& MSRgraph){
    for(int i = 0; i<MSRgraph.GetSize(); i++){
        /*
        if(MSRgraph.coarsedBits[i]){
            continue;
        }
        */
    }
}

void GraphPartitioning(){
    return;
}

void GraphUncoarsening(){
    return;
}

int main(){
    // Graph creation
    int graph[NODES_COUNT*NODES_COUNT] = {0};
    int convGraph[NODES_COUNT*NODES_COUNT] = {0};
    vector<int> mergedNodes[NODES_COUNT/2]; // That means that NODES_COUNT is even and that the coarsening is going to reduce to 1/2 the graph
    vector<int> coarsedGraph[NODES_COUNT/2]; // That means that NODES_COUNT is even and that the coarsening is going to reduce to 1/2 the graph
    GenerateGraphMat(graph, NODES_COUNT, 0.1f);

    MSR MSRgraph(NODES_COUNT);
    MSRgraph.CompressGraphMat(graph);

    // Graph coarsening

    // Partition of the coarsed graph

    // Graph uncoarsening

    // Print results
    PrintGraph(graph, NODES_COUNT);
    MSRtoMat(MSRgraph, convGraph);
    if(compareMat(graph, convGraph, NODES_COUNT)){
        cout << "MSR is working!" << endl;
    } else {
        cout << "MSR is not working!" << endl;
    }
}
