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

    void bfs(int index, vector<int> &visited)
    {
        queue<int> q;
        q.push(index);
        visited[index] = true;
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
                }
            }
        }
    }

    int num_component()
    {
        int num = 0;
        vector<int> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited);
                num++;
            }
        }
        return num;
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
    int n = 10;
    Graph g(n);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 9);
    g.addEdge(2, 7);
    g.addEdge(5, 6);
    cout << g.num_component() << endl;
    return 0;
}