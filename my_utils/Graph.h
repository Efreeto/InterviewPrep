
#define DIJKSTRA_INF 999
class Graph
{
protected:
	int n;	// number of vertices
	int **A;	// edges
public:
	Graph(int size = 2);
	~Graph();
	virtual bool isConnected(int, int);
	void addEdge(int u, int v);
	void BFS(int);
	void DFS(int);
};

class WeightedGraph : public Graph
{
public:
	WeightedGraph(int size = 2);
	//WeightedGraph(int size = 2) : Graph(size)
	//{
	//	int i, j;
	//	for (i = 0; i < n; i++)
	//		for (j = 0; j < n; j++)
	//			A[i][j] = DIJKSTRA_INF;
	//};
	bool isConnected(int, int);
	void addEdge(int u, int v, int weight);
	void Dijkstra(int);	// similar to BFS
};