#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <tuple>
#include <utility>
#include <vector>

#define NODES_COUNT 10
#define MIN_EDGES_COUNT 5


using namespace std;

struct Graph{
    vector<int> values; // the first NODES_COUNT values are the diagonal, the others are the non-zero values row-wise
    vector<int> bindCol; //the first NODES_COUNT values are the start of the row in the values array, the others are the column values
};


void GenerateGraph(int** graph, int n, float sparsity){
    return;
}


void MSRcompression(int** graph, int size, Graph& MSRgraph){

    MSRgraph.values = {};
    MSRgraph.bindCol = {};

    // COPY DIAGONAL
    for(int ij = 0; ij<size; ij++){
        MSRgraph.values.push_back(graph[ij][ij]);
    }

    vector<int> columns = {};
    for(int i = 0; i<size; i++){
        bool firstFound = false;
        for(int j = 0; j<size; j++){
            if(i == j){
                continue;
            }
            if(graph[i][j] == 0){
                continue;
            }

            int idxValue = MSRgraph.values.size();
            MSRgraph.values.push_back(graph[i][j]);
            columns.push_back(j);
            if(!firstFound)
                MSRgraph.bindCol.push_back(idxValue);

            firstFound = true;
        }
    }

    for(int& column : columns){
        MSRgraph.bindCol.push_back(column);
    }
}

void GraphCoarsening(){
    return;
}

void GraphPartitioning(){
    return;
}

void GraphUncoarsening(){
    return;
}

int main(){
    // Graph creation
    int** graph;
    vector<int> mergedNodes[NODES_COUNT/2]; // That means that NODES_COUNT is even and that the coarsening is going to reduce to 1/2 the graph
    vector<int> coarsedGraph[NODES_COUNT/2]; // That means that NODES_COUNT is even and that the coarsening is going to reduce to 1/2 the graph
    GenerateGraph(graph, NODES_COUNT, 0.1f);

    Graph   MSRgraph;
    MSRcompression(graph, NODES_COUNT, MSRgraph);

    // Graph coarsening

    // Partition of the coarsed graph

    // Graph uncoarsening

    // Print results

}
