/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> graph;
    vector<int> inDegree;

public:
    Graph(int v)
    {
        this->V = v;
        graph.resize(v, vector<int>());
        inDegree.resize(V, 0);
    }

    void addEdge(int u, int v)
    {
        inDegree[v]++;
        graph[u].push_back(v);
    }

    void topological_sort()
    {
        vector<int> tmp_inDegree = inDegree;
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (!tmp_inDegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int child : graph[curr])
            {
                tmp_inDegree[child]--;
                if (!tmp_inDegree[child])
                    q.push(child);
            }
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
    g.addEdge(3, 2);
    g.topological_sort();
    return 0;
}