#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
// problem link: https://leetcode.com/problems/rotting-oranges/description/
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0; // Handle empty grid case
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int fresh = 0;
        int time = 0;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int rdx = r + dx[i];
                int cdy = c + dy[i];
                if (rdx >= 0 && cdy >= 0 && rdx < n && cdy < m && grid[rdx][cdy] == 1 && visited[rdx][cdy] == 0)
                {
                    q.push({{rdx, cdy}, t + 1});
                    visited[rdx][cdy] = 1;
                    fresh--;
                }
            }
        }
        return fresh == 0 ? time : -1;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}