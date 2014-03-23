#include "Graph.h"

int main(){
	Graph g(8);
	g.addEdge(1, 2); g.addEdge(1, 3); g.addEdge(1, 4);
	g.addEdge(2, 5); g.addEdge(2, 6); g.addEdge(4, 7);
	g.addEdge(4, 8);
	g.DFS(1);

	Graph g2(12);
	g2.addEdge(1, 2); g2.addEdge(1, 3);
	g2.addEdge(2, 4); g2.addEdge(3, 4);
	g2.addEdge(3, 6); g2.addEdge(4, 7);
	g2.addEdge(5, 6); g2.addEdge(5, 7);
	g2.BFS(1);

	WeightedGraph g3(6);
	g3.addEdge(1, 2, 4); g3.addEdge(1, 3, 2);
	g3.addEdge(2, 3, 1); g3.addEdge(2, 4, 5);
	g3.addEdge(3, 4, 8); g3.addEdge(3, 5, 10);
	g3.addEdge(4, 5, 2); g3.addEdge(4, 6, 6);
	g3.addEdge(5, 6, 3);
	g3.Dijkstra(1);
	return 0;
}