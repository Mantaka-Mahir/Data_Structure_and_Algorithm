#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link : https://leetcode.com/problems/search-in-a-binary-search-tree/
// time complexity: O(h) → h is the height of the BST (O(log n) if balanced, O(n) if skewed)
// space complexity: O(1) → uses only a constant number of variables, no recursion or extra data structures


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *temp = root;
        while (temp)
        {
            if (temp->val == val)
                return temp;
            else if (temp->val > val)
                temp = temp->left;
            else
                temp = temp = temp->right;
        }
        return temp;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}