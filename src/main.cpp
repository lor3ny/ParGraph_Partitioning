#include <iostream>
#include <cstdlib>
#include "CSR.hpp"
#include "Coarser.hpp"

#define NODES_COUNT 8
#define SPARSITY 0.3f

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
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++)
        {
            cout << g[j+i*size] << " ";
        }
        cout << endl;
    }
    cout << endl;
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


void CSRGraphCoarsening(CSR& CSRgraph){
    for(int i = 0; i<CSRgraph.GetSize(); i++){
        /*
        if(CSRgraph.coarsedBits[i]){
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
    int testGraph[NODES_COUNT*NODES_COUNT] = {0};

    GenerateGraphMat(graph, NODES_COUNT, SPARSITY);

    CSR CSRgraph(NODES_COUNT);
    CSRgraph.CompressGraphMat(graph);

    // Graph coarsening
    // REMEMBER: It's meaningless to converto a coarsed graph to a matrix, because the nodes maintain their IDs but the size decrease
    Coarser coarser(&CSRgraph);
    CSR CSRcoarGraph = coarser.CoarsCSR();

    // Partition of the coarsed graph

    // Graph uncoarsening

    // RESULTS PRINTING

    PrintGraph(graph, NODES_COUNT);
    CSRgraph.CSRtoMat(testGraph, NODES_COUNT);

    CSRgraph.PrintCSR();
    CSRcoarGraph.PrintCSR();


    if(compareMat(graph, testGraph, NODES_COUNT)){
        cout << "CSR is working!" << endl;
    } else {
        cout << "CSR is not working!" << endl;
    }
}
