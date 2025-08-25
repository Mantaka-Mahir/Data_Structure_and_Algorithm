#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/is-graph-bipartite/
// time complexity:
// space complexity:
class Solution
{
private:
    bool dfs(vector<int> &color, vector<vector<int>> &graph, int node, int colour)
    {
        color[node] = colour;
        for (auto itr : graph[node])
        {
            if (color[itr] == -1)
            {
                if (dfs(color, graph, itr, !colour) == false)
                {
                    return false;
                }
            }
            else if (color[itr] == colour)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(color, graph, i, 0) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}