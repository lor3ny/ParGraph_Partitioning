#include <iostream>
#include <list>


using namespace std;

// is it better to use a adjacency matrix and select a well known memory strategy or adjacency lists?

int main(){

    // Graph creation

    // Graph coarsening

    // Partition of the coarsed graph

    // Graph uncoarsening

    // Print results
}

bool IsThere(list<int> collection, int elem){

    // Find elem on collection

    return false;
}


list<int> generateGraphs(int nodesCount, int maxOutedges){

    // A dynamic structure is needed
    
    list<int> nodes[nodesCount]; //array of lists
    for(int i=0; i<nodesCount; i++){

        // nodes[i] = [];

        for(int j = 0; i< (maxOutedges - nodes[i].size()); i++){
            // Pick random integer between 0 and nodesCount
            
            int newEdge = random(0, nodesCount); // Use a library

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