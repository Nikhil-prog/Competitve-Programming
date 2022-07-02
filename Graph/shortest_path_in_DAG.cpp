/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> graph;
    map<pair<int, int>, int> weights;

public:
    Graph(int v)
    {
        this->V = v;
        graph.resize(v, vector<int>());
        weights.clear();
    }

    void addEdge(int u, int v, int wt)
    {
        graph[u].push_back(v);
        weights[{u, v}] = wt;
    }

    void dfs(int curr, stack<int> &st, vector<bool> &visi)
    {
        visi[curr] = true;
        for (int child : graph[curr])
        {
            if (!visi[child])
            {
                dfs(child, st, visi);
            }
        }
        st.push(curr);
    }

    stack<int> topo_sorting()
    {
        stack<int> top_sort;
        vector<bool> visi(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visi[i])
            {
                dfs(i, top_sort, visi);
            }
        }
        return top_sort;
    }

    void shortestPath(int source)
    {
        vector<int> dist(V, INT_MAX);
        stack<int> topo_sort = topo_sorting();

        dist[source] = 0;
        while (!topo_sort.empty())
        {
            int curr = topo_sort.top();
            topo_sort.pop();

            for (int child : graph[curr])
            {
                if (dist[curr] != INT_MAX)
                {
                    if (dist[child] > dist[curr] + weights[{curr, child}])
                    {
                        dist[child] = dist[curr] + weights[{curr, child}];
                    }
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                cout << "Node " << i << " : Inf" << endl;
            }
            else
            {
                cout << "Node " << i << " : " << dist[i] << endl;
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);

    int s = 0;
    cout << "Following are shortest distances from source " << s << " \n";
    g.shortestPath(s);

    return 0;
}