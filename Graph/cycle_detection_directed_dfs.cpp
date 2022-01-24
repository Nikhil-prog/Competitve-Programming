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
    }

    bool dfsRec(int curr, vector<bool> &visited, vector<bool> &currParent)
    {
        visited[curr] = true;
        currParent[curr] = true;
        for (int child : graph[curr])
        {
            if (!visited[child])
            {
                if (dfsRec(child, visited, currParent))
                    return true;
            }
            else if (currParent[child])
            {
                return true;
            }
        }
        currParent[curr] = false;
        return false;
    }

    bool cycle_detect()
    {
        vector<bool> visited(V, false), currParent(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfsRec(i, visited, currParent))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    if (g.cycle_detect())
    {
        cout << "Cycle exists in the Graph\n";
    }
    else
    {
        cout << "Cycle DOES NOT exists in the Graph\n";
    }
    return 0;
}