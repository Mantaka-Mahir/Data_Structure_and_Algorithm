#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// pl2:https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// time complexity:
// space complexity:

class Solution
{
public:
    void inorder_traversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inorder_traversal(root->left, inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right, inorder);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorder_traversal(root, inorder);
        return inorder[k - 1];
    }
};
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void inorder_traversal(Node *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inorder_traversal(root->right, inorder);
        inorder.push_back(root->data);
        inorder_traversal(root->left, inorder);
    }
    int kthLargest(Node *root, int k)
    {
        // Your code here
        vector<int> inorder;
        inorder_traversal(root, inorder);
        return inorder[k - 1];
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}