#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/01-matrix/
// time complexity:
// space complexity:
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
                else
                {
                    visited[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int rx = r + dx[i];
                int cy = c + dy[i];
                if (rx >= 0 && rx < m && cy >= 0 && cy < n && visited[rx][cy] == 0)
                {
                    visited[rx][cy] = 1;
                    ans[rx][cy] = distance + 1;
                    q.push({{rx, cy}, distance + 1});
                }
            }
        }
        return ans;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}