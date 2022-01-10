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
		graph.resize(v, vector<int>());
	}

	void addEdge(int u, int v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u); // remove this in case of directed graph
	}

	void print()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << " has neighbour as >> ";
			for (int j = 0; j < graph[i].size(); j++)
			{
				cout << j << " ";
			}
			cout << "\n";
		}
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 3);
	g.print();
	return 0;
}