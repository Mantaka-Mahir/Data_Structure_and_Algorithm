#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

/*
DFS (Depth First Search) traversal of a graph.

How DFS works here:
- We start from node 0 (or any start node).
- Mark node as visited.
- Add node to traversal list.
- Recursively visit all unvisited neighbors.
- Recursion goes deep into one path until no more unvisited neighbors.
- Then backtracks and explores other paths.
- Finally, all reachable nodes from start are visited in DFS order.
*/

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node] = 1;      // Mark current node visited to avoid revisiting
        ls.push_back(node); // Add node to DFS traversal list

        // Traverse all neighbors of current node
        for (auto it : adj[node])
        {
            // If neighbor not visited, recurse on neighbor
            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
        // When all neighbors visited, this call returns (backtracks)
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0}; // Visited array initialized to 0 (unvisited)
        int start = 0;    // Starting DFS from node 0

        vector<int> ls; // List to store DFS traversal order

        dfs(start, adj, vis, ls); // Call recursive DFS

        return ls; // Return the DFS traversal list
    }
};

// Helper function to add an undirected edge between u and v
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Helper function to print the traversal result
void printAns(vector<int> &ans)
{
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    fast;

    vector<int> adj[5]; // Graph with 5 nodes numbered 0 to 4

    // Add edges (undirected)
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj); // Get DFS traversal starting from 0

    printAns(ans); // Print DFS traversal order

    return 0;
}
