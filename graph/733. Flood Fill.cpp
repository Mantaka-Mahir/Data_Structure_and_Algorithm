#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/flood-fill/
// time complexity:
// space complexity:
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int og_color = image[sr][sc];
        image[sr][sc] = color;
        if (color == og_color)
            return image;
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int rx = r + dx[i];
                int cy = c + dy[i];
                if (rx >= 0 && cy >= 0 && rx < m && cy < n && image[rx][cy] == og_color)
                {
                    image[rx][cy] = color;
                    q.push({rx, cy});
                }
            }
        }
        return image;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}