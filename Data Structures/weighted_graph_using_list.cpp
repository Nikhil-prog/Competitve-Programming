/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;
using p = pair<int, int>;

class Graph
{
	int V;
	vector<vector<p>> graph;

public:
	Graph(int v)
	{
		this->V = v;
		graph.resize(v, vector<p>());
	}

	void addEdge(int u, int v, int weight)
	{
		graph[u].push_back({v, weight});
		graph[v].push_back({u, weight}); // remove this in case of directed graph
	}

	void print()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << " has neighbour as >> ";
			for (int j = 0; j < graph[i].size(); j++)
			{
				cout << "(" << graph[i][j].first << " has weight " << graph[i][j].second << " ) ";
			}
			cout << "\n";
		}
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1, 3);
	g.addEdge(0, 2, 5);
	g.addEdge(0, 3, 1);
	g.addEdge(2, 3, 10);
	g.print();
	return 0;
}