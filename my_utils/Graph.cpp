#include <iostream>
#define GRAPH_USE_STL 1
#if GRAPH_USE_STL
#include <queue>
#include <stack>
#else
#include "Queue.h"
#include "Stack.h"
#endif
#define DIJKSTRA_INF 999
#include "Graph.h"
using namespace std;

Graph::Graph(int size){
	int i, j;
	if (size < 2)
		n = 2;
	else
		n = size;
	A = new int*[n];
	for (i = 0; i < n; i++)
	{
		A[i] = new int[n];
	}
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		A[i][j] = 0;
}
Graph::~Graph() {
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}
bool Graph::isConnected(int u, int v) {
	return (A[u - 1][v - 1] == 1);
}
void Graph::addEdge(int u, int v) {
	A[u - 1][v - 1] = A[v - 1][u - 1] = 1;
}

void Graph::BFS(int s) {
#if GRAPH_USE_STL
	queue<int> Q;
#else
	Queue Q;
#endif

	/** Keeps track of visited vertices */
	bool *visited = new bool[n + 1];

	/** Initailized all vertices as unexplored */
	for (int i = 1; i <= n; ++i)
		visited[i] = false;

	/** Push initial vertex to the queue */
#if GRAPH_USE_STL
	Q.push(s);
#else
	Q.enqueue(s);
#endif
	visited[s] = true; /** mark it as explored */
	cout << "Breadth first Search starting from vertex ";
	cout << s << " : " << endl;

	/** Unless the queue is empty */
#if GRAPH_USE_STL
	while (!Q.empty()) {
#else
	while (!Q.isEmpty()) {
#endif

		/** Pop the vertex from the queue */
#if GRAPH_USE_STL
		int v = Q.front();
		Q.pop();
#else
		int v = Q.dequeue();
#endif

		/** display the explored vertices */
		cout << v << " ";

		/** From the explored vertex v try to explore all the
		connected vertices */
		for (int w = 1; w <= n; ++w)

			/** Explores the vertex w if it is connected to v
			and and if it is unexplored */
		if (isConnected(v, w) && !visited[w]) {
			/** adds the vertex w to the queue */
#if GRAPH_USE_STL
			Q.push(w);
#else
			Q.enqueue(s);
#endif
			/** marks the vertex w as visited */
			visited[w] = true;
		}
	}
	cout << endl;
	delete[] visited;
}

void Graph::DFS(int x){
#if GRAPH_USE_STL
	stack<int> s;
#else
	Stack s;
#endif
	bool *visited = new bool[n + 1];
	int i;
	for (i = 1; i <= n; i++)
		visited[i] = false;
	s.push(x);
	visited[x] = true;
	//if (x == dest) return;	/*  To end the search at the destination, comment out this line and the other line below and take 'int dest' as parameter.
	cout << "Depth first Search starting from vertex ";
	cout << x << " : " << endl;
#if GRAPH_USE_STL
	while (!s.empty()){
#else
	while (!s.isEmpty()){
#endif
#if GRAPH_USE_STL
		int k = s.top();
		s.pop();
#else
		int k = s.pop();
#endif
		//if (k == dest) break;	/* comment out */
		cout << k << " ";
		for (i = n; i > 0; --i)
		if (isConnected(k, i) && !visited[i]) {
			s.push(i);
			visited[i] = true;
		}
	}
	cout << endl;
	delete[] visited;
}


/* Calls inherited constructor of 'Graph' first, then calls this constructor, as intended. */
WeightedGraph::WeightedGraph(int size) : Graph(size)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = DIJKSTRA_INF;
}
void WeightedGraph::Dijkstra(int x)
{
	// For each node, ...
	int* predecessor = new int[n+1];	//keep track of the shortest distance predecessor
	int* distance = new int[n+1];	//keep track of the shortest distance
	bool* visited = new bool[n+1]; //keep track of visited node
	for (int i = 1; i<=n; i++)
	{
		visited[i] = false;
		predecessor[i] = -1;
		distance[i] = DIJKSTRA_INF;
	}
	distance[x] = 0;

	for (int k = 1; k <= n; ++k)
	{
		int small_i;	// the vertex to be checked in each loop
		int minDistance = DIJKSTRA_INF;

		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i] && (distance[i] < minDistance))
			{
				minDistance = distance[i];
				small_i = i;
			}
		}

		// Mark the picked vertex as processed
		visited[small_i] = 1;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int i = 1; i <= n; ++i)
			if (isConnected(small_i, i) && (distance[i] > distance[small_i] + A[small_i - 1][i - 1]) )
				distance[i] = distance[small_i] + A[small_i-1][i-1];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": " << distance[i] << endl;
	}
	delete[] predecessor;
	delete[] distance;
	delete[] visited;
}
bool WeightedGraph::isConnected(int u, int v) {
	return (A[u - 1][v - 1] != DIJKSTRA_INF);
}
void WeightedGraph::addEdge(int u, int v, int weight) {
	A[u - 1][v - 1] = A[v - 1][u - 1] = weight;
}