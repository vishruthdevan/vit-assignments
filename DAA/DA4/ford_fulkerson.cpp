// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <vector>
#include <string.h>
using namespace std;

bool bfs(vector<vector<int>> &RG, int s, int t, vector<int> &parent, int V)
{
    vector<bool> visited(V, false);

    vector<int> queue;
    queue.push_back(s);
    visited[s] = true;
    parent[s] = -1;

    while (!queue.empty())
    {
        int u = queue.front();
        queue.erase(queue.begin());

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && RG[u][v] > 0)
            {
                parent[v] = u;
                if (v == t)
                    return true;
                queue.push_back(v);
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>> &C, int s, int t, int V)
{
    int u, v;

    vector<vector<int>> RG(V, vector<int>(V));
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            RG[u][v] = C[u][v];

    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(RG, s, t, parent, V))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = path_flow < RG[u][v] ? path_flow : RG[u][v];
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            RG[u][v] -= path_flow;
            RG[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int V = 8;
    vector<vector<int>> C = {{0, 13, 10, 10, 0, 0, 0, 0},
                             {0, 0, 0, 0, 24, 0, 0, 0},
                             {0, 5, 0, 15, 0, 0, 7, 0},
                             {0, 0, 0, 0, 0, 0, 15, 0},
                             {0, 0, 0, 0, 0, 1, 0, 9},
                             {0, 0, 0, 0, 0, 0, 6, 13},
                             {0, 0, 0, 0, 0, 0, 0, 16},
                             {0, 0, 0, 0, 0, 0, 0, 0}};

    cout << "The maximum possible flow is "
         << fordFulkerson(C, 0, 7, V);

    return 0;
}
