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

    void bfs(int index)
    {
        vector<int> visited(V, false);
        vector<int> level(V, INT_MAX);
        queue<int> q;

        q.push(index);
        visited[index] = true;
        level[index] = 0;
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();

            for (auto it = graph[parent].begin(); it != graph[parent].end(); it++)
            {
                int child = *it;
                if (!visited[child])
                {
                    visited[child] = true;
                    q.push(child);
                    level[child] = level[parent] + 1;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout << i << " " << level[i] << endl;
        }
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
    int n = 6;
    Graph g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.bfs(0);
    return 0;
}