#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// time complexity:
// space complexity:
class Solution
{
private:
    bool dfs(vector<int> &visited, vector<vector<int>> &adj, int node, int parent)
    {
        visited[node] = 1;
        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                if (dfs(visited, adj, itr, node))
                    return true;
            }
            else if (parent != itr)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<vector<int>> adj(V);
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(visited, adj, i, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution
{
public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> adj[V];
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                queue<pair<int, int>> q;
                q.push({i, -1});
                while (!q.empty())
                {
                    int node = q.front().first;
                    int parent_node = q.front().second;
                    q.pop();
                    for (auto itr : adj[node])
                    {
                        if (!visited[itr])
                        {
                            visited[itr] = 1;
                            q.push({itr, node});
                        }
                        else if (parent_node != itr)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}