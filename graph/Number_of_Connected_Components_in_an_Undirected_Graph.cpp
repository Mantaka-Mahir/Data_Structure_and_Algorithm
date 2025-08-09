#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link: https://neetcode.io/problems/count-connected-components

// In this problem, we need to find how many connected components are in a graph.
// A connected component is defined as:
// "A set of nodes where every pair has a path between them."
// That means each node in a component is reachable from any other node in the same component.

// There are three common methods to solve this problem:
// 1) DFS (Depth First Search)
// 2) BFS (Breadth First Search)
// 3) Union-Find (Disjoint Set Union - DSU)

// Both DFS and BFS work fine, but DFS might cause recursion depth issues (stack overflow) on very large inputs.
// BFS is usually safer in terms of recursion limits since it uses a queue and iterative approach.
// Union-Find is usually fastest and most efficient for dynamic connectivity problems.

// Let's see how BFS works for this problem:

/*
BFS approach:
- We create an adjacency list from the edges for easy traversal.
- We maintain a visited array to keep track of visited nodes.
- For each node:
    - If it is not visited:
        - Run BFS starting from this node, which will visit all nodes in this connected component.
        - Increase the count of connected components by 1.
- Finally, return the count of connected components.
*/

// BFS solution
class SolutionBFS
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        // Build adjacency list
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0; // to count connected components

        // Check each node
        for (int node = 0; node < n; ++node)
        {
            if (!visit[node])
            {
                bfs(adj, visit, node); // visit all connected nodes from this node
                res++;                 // found one connected component
            }
        }
        return res;
    }

private:
    void bfs(vector<vector<int>> &adj, vector<bool> &visit, int node)
    {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            // Visit all neighbors of current node
            for (int nei : adj[cur])
            {
                if (!visit[nei])
                {
                    visit[nei] = true;
                    q.push(nei);
                }
            }
        }
    }
};

/*
DFS approach:
- Similar to BFS, but uses recursion instead of a queue.
- From an unvisited node, recursively visit all its neighbors.
- Recursion explores each branch as deep as possible before backtracking.
- Each time we start DFS from an unvisited node, it means we found a new connected component.
- Return the count of connected components.
- Note: DFS can cause stack overflow for very large graphs if recursion is too deep.
*/

class SolutionDFS
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        // Build adjacency list
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0; // connected components count

        // Check all nodes
        for (int node = 0; node < n; ++node)
        {
            if (!visit[node])
            {
                dfs(adj, visit, node); // visit all connected nodes recursively
                res++;                 // one more connected component found
            }
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>> &adj, vector<bool> &visit, int node)
    {
        visit[node] = true; // mark current node visited
        for (int nei : adj[node])
        {
            if (!visit[nei])
            {
                dfs(adj, visit, nei); // recursively visit neighbors
            }
        }
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
