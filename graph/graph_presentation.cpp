#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

/*
  Graph basics : https://takeuforward.org/graph/introduction-to-graph/
  Graph representation: https://takeuforward.org/graph/graph-representation-in-c/

  Graph representation types:
    1. Adjacency Matrix
    2. Adjacency List

  Adjacency Matrix:
    - Input number of nodes (n) and edges (m)
    - Create a n*n matrix (0-based or 1-based)
    - If 1-based, use size n+1
    - Input edges (a, b) and set adj[a][b] and adj[b][a] = 1
    - For weighted graphs, store weight instead of 1
    - Space: O(N^2) (costly for large N)

  Adjacency List:
    - Create an array of vectors
    - Each index stores the nodes it's connected to
    - Space: O(2E) for undirected graphs, O(E) for directed
    - For weighted graphs, store pairs {node, weight}
*/

void graph_storing_matrices_method()
{
    int node_count, edge_count;
    cin >> node_count >> edge_count;
    int adj[node_count][node_count] = {0}; // assuming 0-based index
    for (int i = 0; i < edge_count; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1; // for undirected graphs
        // for weighted: adj[a][b] = weight;
    }
    // Time Complexity: O(N^2)
}

void adj_list_method()
{
    int node_count, edge_count;
    cin >> node_count >> edge_count;
    vector<int> adj[node_count]; // 0-based indexing
    for (int i = 0; i < edge_count; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // remove if directed graph
    }
}

// Weighted adjacency list using pair
void weighted_adj_list_method()
{
    int node_count, edge_count;
    cin >> node_count >> edge_count;
    vector<vector<pair<int, int>>> adj(node_count); // {neighbor, weight}

    for (int i = 0; i < edge_count; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // remove if directed graph
    }

    // Printing adjacency list
    cout << "Weighted Graph Adjacency List:\n";
    for (int i = 0; i < node_count; i++)
    {
        cout << "Node " << i << ": ";
        for (auto &edge : adj[i])
        {
            cout << "(to " << edge.first << ", w=" << edge.second << ") ";
        }
        cout << "\n";
    }
}

int32_t main()
{
    fast;

    // Example usage:
    // weighted_adj_list_method();

    return 0;
}
