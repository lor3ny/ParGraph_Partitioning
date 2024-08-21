#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

#define NODES_COUNT 20
#define MIN_EDGES_COUNT 5


using namespace std;

struct Graph{
    vector<int> values; // the first NODES_COUNT values are the diagonal, the others are the non-zero values row-wise
    vector<int> bindCol; //the first NODES_COUNT values are the start of the row in the values array, the others are the column values
    int size;
};

void PrintGraph(int (&g)[NODES_COUNT][NODES_COUNT], int size){
    cout << "STARTING GRAPH N=" << size << endl;
    for(int i = 0; i<NODES_COUNT; i++){
        for(int j = 0; j<NODES_COUNT; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void PrintGraphMSR(Graph& g){
    cout << "MSR GRAPH N=" << g.size << endl;
    cout << "Values: ";
    for(int& v : g.values)
        cout << v << " ";
    cout << endl;
    cout << "Bind: ";
    for(int& b : g.bindCol)
        cout << b << " ";
    cout << endl;

    
    for(int i = 0; i<g.size; i++){
        // col = i+(n)
        int rowStart = g.bindCol[i];
        int rowEnd = g.bindCol[i+1];
        if(rowStart == -1){
            for(int k = 0; k<g.size; k++){
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        if(rowEnd == -1){
            rowEnd = g.bindCol[i+2];
        }

        int lastCol = 0;
        for(int j = rowStart; j < rowEnd; j++){
            for(int k = lastCol; k < g.bindCol[j]; k++){
                if(k==i)
                    cout << g.values[i] << " ";
                else
                    cout << 0 << " ";
            }
            cout << g.values[j] << " ";
            lastCol = g.bindCol[j]+1;

            if(j == rowEnd-1){
                for(int k = lastCol; k<g.size; k++){
                    cout << 0 << " ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}


void GenerateGraph(int (&graph)[NODES_COUNT][NODES_COUNT], int n, float sparsity){

    for(int i = 0; i<NODES_COUNT; i++){
        for(int j = 0; j<NODES_COUNT; j++)
        {
            if(graph[i][j] == 1){
                continue;
            }

            float occurrence = (rand() % 100)/100.0f;
            if(occurrence < sparsity){
                graph[i][j] = 1;
                graph[j][i] = 1;
            } else {
                graph[i][j] = 0;
            }
        }
    }


    return;
}

// -1 flags that the row is a zero-row
void MSRcompression(int (&graph)[NODES_COUNT][NODES_COUNT], int size, Graph& MSRgraph){
    MSRgraph.values = {};
    MSRgraph.bindCol = {};
    MSRgraph.size = size;

    // COPY DIAGONAL
    for(int ij = 0; ij<size; ij++){
        MSRgraph.values.push_back(graph[ij][ij]);
    }
    MSRgraph.values.push_back(-1);

    vector<int> columns = {};
    for(int i = 0; i<size; i++){
        bool firstFound = false;
        bool zeroRow = true;
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
            zeroRow = false;
        }
        if(zeroRow){
            MSRgraph.bindCol.push_back(-1);
        }
    }
    MSRgraph.bindCol.push_back(MSRgraph.values.size());

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
    int graph[NODES_COUNT][NODES_COUNT];
    vector<int> mergedNodes[NODES_COUNT/2]; // That means that NODES_COUNT is even and that the coarsening is going to reduce to 1/2 the graph
    vector<int> coarsedGraph[NODES_COUNT/2]; // That means that NODES_COUNT is even and that the coarsening is going to reduce to 1/2 the graph
    GenerateGraph(graph, NODES_COUNT, 0.1f);

    Graph MSRgraph;
    MSRcompression(graph, NODES_COUNT, MSRgraph);

    // Graph coarsening

    // Partition of the coarsed graph

    // Graph uncoarsening

    // Print results
    PrintGraph(graph, NODES_COUNT);
    PrintGraphMSR(MSRgraph);
}
