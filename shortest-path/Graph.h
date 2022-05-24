#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

typedef vector<vector<int> > Matrix;

class Graph{

  Matrix graph;

public:
  Graph(int nNodes, int nEdges){
    // you don't have to change anything here. This function will generate a random weighted graph given the
    // desired parameters (number of nodes and number of edges)
    srand (time(NULL));

    graph = Matrix(nNodes, vector<int>(nNodes,0));

    for(int i=0; i<nEdges; i++){
      //random weight
      int weight = 0;
      while(weight == 0) weight = rand()%(101);
      int node1, node2;

      do{
        node1 = rand()%(nNodes);
        node2 = rand()%(nNodes);
      }while(node1 == node2 && !connected(node1,node2));

      graph[node1][node2] = graph[node2][node1] = weight;
    }

  }

  //### return the number of nodes in the graph
  int size(){
    return graph.size();
  }

  //### return a list with the nodes connected to node
  list<int> getConnectedNodes(int n){
    list<int> connections;
    for (int i = 0; i < graph.size(); i++){
        if (graph[n][i] != 0){
          connections.__emplace_back(i);
        }
    }
    
    return connections;
  }

  //### return the weight assigned to a node
  int getEdgeWeight(int n, int n2){
    return graph[n][n2];
  }

  //### return true if the two nodes are connected
  bool connected(int n, int n2){
    if (graph[n][n2] != 0){
      return true;
    }
    return false;
  }

  //### you can implement this for debugging purposes
  void print(){
    for (int a = 0; a < size(); a++){
      cout << a << " : ";
      for (int b = 0; b < size(); b++){
        if (connected(a,b)){
          cout << b << " , ";
        }
      }
      cout << endl;
    }
  }

};
