#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/word-ladder/description/
// time complexity:
// space complexity:
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.size(); i++)
            {
                char og = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (s.find(word) != s.end())
                    {
                        q.push({word, steps + 1});
                        s.erase(word);
                    }
                    word[i] = og;
                }
            }
        }
        return 0;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}
