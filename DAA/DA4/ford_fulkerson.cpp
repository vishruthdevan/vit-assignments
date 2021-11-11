#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// Breadth first search to find any path from s to t in the residual graph RG
bool bfs(vector<vector<int>> &RG, vector<int> &parent, int s, int t, int V)
{
    vector<bool> visited(V, false);

    vector<int> queue;
    queue.push_back(s);
    visited[s] = true;
    parent[s] = -1;

    while (!queue.empty())
    {
        //Popping the front of the queue to start traversing
        int i = queue.front();
        queue.erase(queue.begin());

        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && RG[i][j] > 0)
            {
                parent[j] = i;
                if (j == t)
                    //If an augmenting path is found from s to t, we return 'true'
                    // after which the flow is augmented
                    return true;

                //pushing all neighbours of the current vertex to traverse through later
                queue.push_back(j);
                visited[j] = true;
            }
        }
    }
    // if no path is found from s to t then we return 'false'
    return false;
}

int fordFulkerson(vector<vector<int>> &C, int s, int t, int V)
{
    // RG is the residual graph containing the residual capacities
    // that is initialized with the capacities C of each edge (i, j)
    vector<vector<int>> RG(V, vector<int>(V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            RG[i][j] = C[i][j];

    vector<int> parent(V);
    int maxFlow = 0, pathFlow;

    // while an augmenting path exists from s to t
    while (bfs(RG, parent, s, t, V))
    {
        // find the mininum capacity edge among all the edges in that path
        pathFlow = INT_MAX;
        for (int j = t; j != s; j = parent[j])
        {
            int i = parent[j];
            pathFlow = pathFlow < RG[i][j] ? pathFlow : RG[i][j];
        }

        // Update the edges and the reverse edges of the path
        // in the residual graph after finding the minimum capacity of the path (pathFlow)
        for (int j = t; j != s; j = parent[j])
        {
            int i = parent[j];
            RG[i][j] -= pathFlow;
            RG[j][i] += pathFlow;
        }

        // pathFlow is added to maxFlow and the process is repeated
        // until no augmenting path exists from s to t
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    // V = number of vertices
    // s = source vertex
    // t = sink vertexc
    int V, s, t;
    cout << "\nEnter the number of vertices in the flow network: ";
    cin >> V;

    cout << "Enter the source vertex: ";
    cin >> s;

    cout << "Enter the sink vertex: ";
    cin >> t;

    // C = matrix with capacities of each edge of the flow network
    vector<vector<int>> C(V, vector<int>(V));
    cout << "Enter the matrix of the flow network:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> C[i][j];

    cout << "\n\nThe maximum flow for the flow network is " << fordFulkerson(C, s, t, V) << "\n\n";

    return 0;
}

// 0 13 10 10  0  0  0  0
// 0  0  0  0 24  0  0  0
// 0  5  0 15  0  0  7  0
// 0  0  0  0  0  0 15  0
// 0  0  0  0  0  1  0  9
// 0  0  0  0  0  0  6 13
// 0  0  0  0  0  0  0 16
// 0  0  0  0  0  0  0  0

// 0 10  0 10  0  0
// 0  0  4  2  8  0
// 0  0  0  0  0 10
// 0  0  0  0  9  0
// 0  0  6  0  0 10
// 0  0  0  0  0  0