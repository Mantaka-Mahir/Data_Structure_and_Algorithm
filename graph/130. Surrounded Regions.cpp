#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/surrounded-regions/description/
// time complexity:
// space complexity:
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && (i == 0 || i == m - 1 || j == 0 || j == n - 1))
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                else if (board[i][j] == 'X')
                {
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int rx = x + dx[i];
                int ry = y + dy[i];
                if (rx >= 0 && rx < m && ry >= 0 && ry < n && visited[rx][ry] == 0 && board[rx][ry] != 'X')
                {
                    visited[rx][ry] = 1;
                    q.push({rx, ry});
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && visited[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}