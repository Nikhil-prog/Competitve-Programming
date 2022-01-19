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
        graph[v].push_back(u); // remove this for directed graph
    }

    void dfsRec(int curr, vector<bool> &visited)
    {
        visited[curr] = true;
        cout << curr << " ";
        for (auto it = graph[curr].begin(); it != graph[curr].end(); it++)
        {
            int child = *it;
            if (!visited[child])
            {
                dfsRec(child, visited);
            }
        }
    }

    void dfs(int index)
    {
        vector<bool> visited(V, false);
        dfsRec(index, visited);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.dfs(0);
    return 0;
}