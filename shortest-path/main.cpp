#include "Graph.h"
#include "Timer.h"
#include <queue>

using namespace std;


int MAX = numeric_limits<int>::max();

//####implement the Dijkstra’s Algorithm here
vector<int> computeShortestPath(Graph g, int node){

cout << "AAAAAAA44444444" << endl;

vector< list<int> > edges;
for (int a = 0; a < g.size(); a++){
  edges[a] = g.getConnectedNodes(a);
}

// //reformats edges into a vector with node1, node2, and weight
// //I preferred this over the other list object in graph.h
// vector<pair<int, int> > edges;

// cout << "AAAAAAA5555555" << endl;

// for (int a = 0; a < g.size(); a++){
//   for (int b = 0; b < g.size(); b++){

//       cout << "BBBBBBBB" << a << a << endl;
//       cout << "CCCCCCCC" << b << b << endl;

//       if (g.connected(a, b)){
//         edges[a] = (make_pair(b, g.getEdgeWeight(a,b)));
//         edges[b] = (make_pair(a, g.getEdgeWeight(a,b)));
//       }
//   }
// }

cout << "AAAAAAA666666" << endl;


//priority queue containing distances between nodes in ascending order
priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> > > q;

//vector containing all distances for nodes
vector<int> distances(g.size(), MAX);

//sets starting node distance to 0
q.push(make_pair(0, node));
distances[node] = 0;

//loop for algorithm
while(!q.empty()){

  int temp = q.top().second;
  q.pop();

  // vector< pair<int,int> >::iterator i;
  // i = edges[temp].begin(); i != edges[temp].end(); i++

  for (int i = 0; i < edges.size(); i++){

    list<int>::iterator j;
    for (j = edges[i].begin(); j != edges[i].end(); j++)
    int num = (*j).first;
    int weight = (*i).second;

    if ((distances[num] > distances[temp] + weight) && (weight != MAX) && (distances[temp] != MAX)){
      distances[num] = distances[temp] + weight;
      q.push(make_pair(distances[num], num));
    }
  }
}

return distances;
};

//####compute all possible shortest paths by calling the Dijkstra's Algorithm on each pair of nodes
vector<vector<int> > computeAllPairsShortestPath(Graph g){

cout << "AAAAAAA222222" << endl;

vector<vector<int> > paths;

cout << "AAAAAAA3333333" << endl;
for (int i = 0; i < g.size(); i++){

  cout << "AAAAAAA" << i << endl;
  
  paths[i] = computeShortestPath(g, i);
}
  
return paths;
};

//####compute all possible shortest paths by implementing the dynamic programming approach
Matrix computeAllPairsShortestPathDynamicProgramming(Graph g){

  Matrix m = Matrix(g.size(), vector<int>(g.size(), MAX));
  
  for (int a = 0; a < g.size(); a++){
    for (int b = 0; b < g.size(); b++){
      if (a == b){
        m[a][b] = 0;
      }

      if (g.connected(a,b)){
        m[a][b] = g.getEdgeWeight(a,b);
      }

      else{
        m[a][b] = MAX;
      }

    }
  }

  for (int k = 0; k < g.size(); k++) {
    for (int i = 0; i < g.size(); i++){
        for (int j = 0; j < g.size(); j++){
            if (m[i][j] > (m[i][k] + m[k][j]) && (m[k][j] != MAX && m[i][k] != MAX))
                    m[i][j] = m[i][k] + m[k][j];
        }
    }
  }

  return m;
};

bool compareResults(Graph g, Matrix a, Matrix b){

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g.size(); j++){
      if(a[i][j] != b[i][j]){
        return false;
      }
    }
  }

  return true;
}


int main(){

  //create graph as a random matrix
  Graph g(10,10);
  cout << "Graph generated " << endl;
  g.print();

  //compute shortest path
  Timer time;
  time.start();
  cout << "AAAAAAA111111" << endl;
  Matrix a = computeAllPairsShortestPath(g);
  time.stop();
  cout << "Time with Dijkstra's algorithm" << time.getElapsedTimeInSec() << endl;

  //compute all possible shortest paths
  time.start();
  Matrix b = computeAllPairsShortestPathDynamicProgramming(g);
  time.stop();
  cout << "Time with Dynamic programming" << time.getElapsedTimeInSec() << endl;

  //compute by dynamic programming approach
  if(compareResults(g,a,b)){
    cout << "They are the same" << endl;
  }
  else{
    cout << "Different" << endl;
  }

};
