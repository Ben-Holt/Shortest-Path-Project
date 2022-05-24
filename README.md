### Shortest-Path-Project

In this assignment, we will implement two distinct algorithms for computing the shortest paths between all possible pairs of nodes in a graph

All the information you need regarding these two data structures can be found in your textbook (Algorithm Analysis and Design, Chapter 14).

### Step 1 - Implementing the graph

We will implement the graph by simply using an adjacency matrix. In the file Graph.h you have the class Graph implementating the graph as an adjacency matrix (a simple vector of vectors).

The constructor of the Graph takes in input two integers indicating the number of nodes and number of arcs. Then, it randomly generates a weighted graph.
You have to implement the remaining functions listed in Graph.h

Keep your code simple.
There is no need for additional files so you can implement everything inline. You should be able to compile your code using the following `g++ Time.cpp main.cpp -o main`.
You are not allowed to reuse code from other classes. Integrate your code into the current structure.

### Step 2 - Implementing the Dijkstra’s Algorithm

The algorithmic description of Dijkstra’s Algorithm can be found in your textbook. A few tips:

- Use `MAX` to represent the maximum distance between two nodes instead of infinite (I have already defined MAX for you).
- You can use the priority queue provided by the standard library. Use the following code for defining the queue.

  `priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> >> q;`

  With this, you are declaring a priority queue made of pairs of integers. Practically, each element in the queue will be a pair of integers (`pair<int,int>,`) and you are creating a vector of pairs (`vector<pair<int,int> >,`). Moreover, the elements will be sorted in ascending order (`greater<pair<int,int> >`).

- By default, if you provide a pair to the priority queue, the first element of the pair will be used for ordering the elements. If you look at Dijkstra’s Algorithm, we want the elements in the queue to be sorted according to their distance from the source. This means that, for each pair, the first element has to encode the distance of the node from the source while the second element has to store the index of such node in the graph.

- The Dijkstra’s Algorithm requires you to update the value of a node in the priority queue. However, searching for a node in the priority queue is an expensive operation. To relax this problem, instead of updating the value in the queue, I suggest you to just push the node in the queue with the updated value. This way the operations involving the queue will all cost `O(logn)` at most. You just have to keep track of the nodes you already processed so to not process them twice.


### Step 3 - Implementing the computeAllPairsShortestPath function

Once the Dijkstra’s Algorithm is implemented this step will be easy. You just have to call the Dijkstra’s Algorithm using as source each possible node in your graph. Save your results in a Matrix such that, for each pair of indices (i,j), Matrix(i,j) will store the length of the shortest between those two nodes.


### Step 4 - Implementing the Dynamic Programming Algorithm

Implement the function `computeAllPairsShortestPathDynamicProgramming` the dynamic programming solution for computing all pairs of shortest pairs (Chapter 14.5.1).


### Step 5 - Analyzing the Dynamic Programming Algorithm

Once both algorithms are implemented, evaluate their performance. Test your implementation with different graphs.

- use a simple graph with 10 nodes and 20 arcs

  [REPORT HERE THE TIMINGS OF THE TWO ALGORITHMS]


- increment the number of nodes to be higher than the number of arcs (1000, 500)

  [REPORT HERE THE TIMINGS OF THE TWO ALGORITHMS]


- increment the number of arcs (1000, 40000)

  [REPORT HERE THE TIMINGS OF THE TWO ALGORITHMS]

Open this README file with a normal text editor and report the timings obtained.
Then, explain why you got such results.
