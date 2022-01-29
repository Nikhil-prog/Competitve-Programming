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
        graph[v].push_back(u);
    }

    bool bfs(int curr, vector<bool> &visited, vector<int> &parent)
    {
        queue<int> q;
        q.push(curr);
        visited[curr] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int child : graph[curr])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    parent[child] = curr;
                    q.push(child);
                }
                else if (child != parent[curr])
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool cycle_detect()
    {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfs(i, visited, parent))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g(10);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 9);
    g.addEdge(2, 7);
    g.addEdge(5, 6);
    g.addEdge(4, 9);
    if (g.cycle_detect())
    {
        cout << "Graph has Cycle" << endl;
    }
    else
    {
        cout << "Graph Does NOT have a Cycle" << endl;
    }
    return 0;
}