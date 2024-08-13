#include <iostream>
#include <cstdlib>
#include <vector>

#define NODES_COUNT 10
#define MIN_EDGES_COUNT 5


using namespace std;

// is it better to use a adjacency matrix and select a well known memory strategy or adjacency lists?

bool IsThere(vector<int> collection, int elem){

    for(int e : collection){
        if(e == elem){
            return true;
        }
    }

    return false;
}

void generateGraph(vector<int>* nodes, int nodesCount, int minOutedges){

    // A dynamic structure is needed
    //array of lists
    for(int i=0; i<nodesCount; i++){

        while(nodes[i].size() < minOutedges){

            // Pick random integer between 0 and nodesCount
            int newEdge = rand() % nodesCount; 

            if(newEdge == i){
                continue;
            } 

            if(IsThere(nodes[i],newEdge)){
                continue;
            }

            nodes[i].push_back(newEdge);
            nodes[newEdge].push_back(i); 
        }
    }
}

void PrintGraph(vector<int>* graph, int nodes){
    cout << "UNDIRECTED GRAPH: " << endl;
    for(int i = 0; i<nodes; i++){
        cout << "node " << i << ": ";
        for (int j = 0; j<graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


void GraphCoarsening(vector<int>* graph){
    
    int halfNodesCount = NODES_COUNT/2;

    vector<int> subGraph[halfNodesCount];


    for(int i = 0; i<halfNodesCount; i++){
        int connNode = graph[i].back(); // Take one node following an heuristics

        // Create a new node that is the union between the two selected nodes

        // The problem are:
        // - which is the most useful structure to create merged nodes? a dictionary?
        // We can create a subgraph storing only the first node and then i create an association list
    }

}

int main(){

    // Graph creation
    vector<int> graph[NODES_COUNT];
    generateGraph(graph, NODES_COUNT, MIN_EDGES_COUNT);

    // Graph coarsening

    // Partition of the coarsed graph

    // Graph uncoarsening

    // Print results
    PrintGraph(graph, NODES_COUNT);

}
