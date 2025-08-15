#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// time complexity: O(h) where h is the height of the tree (O(log n) for balanced, O(n) for skewed)
// space complexity: O(1) iterative approach (O(h) if recursive due to call stack)

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        TreeNode *curr = root;
        while (1)
        {
            if (val >= curr->val)
            {
                if (curr->right != NULL)
                    curr = curr->right;
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (curr->left != NULL)
                    curr = curr->left;
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}