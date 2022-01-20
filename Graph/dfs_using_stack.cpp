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

    void dfs_iter(int source, vector<bool> &visited)
    {
        stack<int> st;
        st.push(source);
        visited[source] = true;
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            cout << curr << " ";
            for (int child : graph[curr])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    st.push(child);
                }
            }
        }
    }

    // use this for multiple disconnected components in graph
    void dfs()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs_iter(i, visited);
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(5, 6);
    g.dfs();
    return 0;
}