/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<vector<int>> graph;

public:
	Graph(int v)
	{
		this->V = v;
		graph.resize(v, vector<int>(v, 0));
	}

	void addEdge(int u, int v, int weight)
	{
		graph[u][v] = weight;
		graph[v][u] = weight; // remove this in case of directed graph
	}

	void print()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << " has neighbour as >> ";
			for (int j = 0; j < V; j++)
			{
				if (graph[i][j])
					cout << "( " << j << " with weight " << graph[i][j] << ") ";
			}
			cout << "\n";
		}
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(0, 3, 1);
	g.addEdge(2, 3, 10);
	g.p();
	return 0;
}