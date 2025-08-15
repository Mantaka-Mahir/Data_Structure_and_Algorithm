#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
// link: https://leetcode.com/problems/number-of-provinces
// this problem is just same as connected component problem
// we can use both dfs bfs and also UNION FIND to solve this problem !
// you need to learn UNION FIND Man

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto itr : adj[node])
        {
            if (!visited[itr])
            {
                dfs(itr, adj, visited);
            }
        }
    }
    void bfs(int node, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        //  vector<int> bfs;
        while (!q.empty())
        {
            int bfs_node = q.front();
            q.pop();
            // bfs.push_back(bfs_node);
            for (auto itr : adj[bfs_node])
            {
                if (!visited[itr])
                {
                    visited[itr] = 1;
                    q.push(itr);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adj(n); // new way of declaring vector<vector<int>>adj  adj list
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j) // i!=j to not get self loops of the graph
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
               // bfs(i, adj, visited);
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};
// Time Complexity: O(n²) due to building adjacency list and BFS traversal over all nodes and edges.
// Space Complexity: O(n²) for storing adjacency list plus O(n) for visited and queue.

int32_t main()
{
    fast;

    // your code here

    return 0;
}