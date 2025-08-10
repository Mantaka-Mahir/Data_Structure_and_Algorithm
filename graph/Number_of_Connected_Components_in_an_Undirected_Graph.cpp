#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link: https://neetcode.io/problems/count-connected-components

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        int visited[n] = {0};
        // converting the edges to adj list
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int counting = 0;
        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                dfs(node, visited, adj); // both
                bfs(node, adj, visited); // both work
                counting++;
            }
        }
        return counting;
    }
    void bfs(int node, vector<vector<int>> &adj, int visited[])
    {
        int n = adj.size();
        queue<int> q;
        vector<int> bfs;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto itr : adj[node])
            {
                if (!visited[itr])
                {
                    visited[itr] = 1;
                    q.push(itr);
                }
            }
        }
    }
    void dfso(int node, vector<int> &ls, vector<vector<int>> &adj, int visited[])
    {
        visited[node] = 1;
        ls.push_back(node);
        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                dfso(itr, ls, adj, visited);
            }
        }
    }
    void dfs(int node, int visited[], vector<vector<int>> &adj)
    {
        visited[node] = 1;
        vector<int> ls;
        dfso(node, ls, adj, visited);
    }
};
/*
Union-Find (Disjoint Set Union - DSU) approach:
- Initialize each node as its own parent (separate set).
- For each edge, union the sets of the two nodes.
- If two nodes are already in the same set, union returns false.
- Initially, the number of connected components = number of nodes.
- Each successful union reduces the count by 1.
- At the end, remaining sets count = connected components count.
- This approach is very efficient for connectivity problems.
*/

class DSU
{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // Initially each node is its own parent
        }
    }

    // Find function with path compression
    int find(int node)
    {
        int cur = node;
        while (cur != parent[cur])
        {
            parent[cur] = parent[parent[cur]]; // path compression for optimization
            cur = parent[cur];
        }
        return cur;
    }

    // Union by rank/size
    bool unionSets(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
        {
            return false; // already in the same set, no union performed
        }
        // union by rank to keep tree flat
        if (rank[pv] > rank[pu])
        {
            swap(pu, pv);
        }
        parent[pv] = pu;      // attach smaller tree under bigger tree root
        rank[pu] += rank[pv]; // update rank/size
        return true;
    }
};

class SolutionUnionFind
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        DSU dsu(n);
        int res = n; // initially, every node is its own component

        for (auto &edge : edges)
        {
            // if union is successful, that means two components joined -> reduce count
            if (dsu.unionSets(edge[0], edge[1]))
            {
                res--;
            }
        }
        return res;
    }
};

int32_t main()
{
    fast;

    return 0;
}
