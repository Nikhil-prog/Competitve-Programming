/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/* Assumption: This DFS approach only works in case of DAG */
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

    void dfs(vector<bool> &visi, vector<int> &res, int curr)
    {
        visi[curr] = true;
        for (int child : graph[curr])
        {
            if (!visi[child])
            {
                dfs(visi, res, child);
            }
        }
        res.push_back(curr);
    }

    void topological_sort()
    {
        vector<int> res;
        vector<bool> visi(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visi[i])
            {
                dfs(visi, res, i);
            }
        }

        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }
        cout << endl;
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
    g.topological_sort();
    return 0;
}