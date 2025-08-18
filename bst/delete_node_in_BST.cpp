#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://leetcode.com/problems/delete-node-in-a-bst/
// time complexity:
// space complexity:

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            return connector(root);
        }
        TreeNode *temp = root;
        while (temp != NULL)
        {
            if (temp->val > key)
            {
                if (temp->left != NULL && temp->left->val == key)
                {
                    temp->left = connector(temp->left);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right != NULL && temp->right->val == key)
                {
                    temp->right = connector(temp->right);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return root;
    }
    TreeNode *find_last_right(TreeNode *root)
    {
        if (root->right == NULL)
            return root;
        else
            return find_last_right(root->right);
    }
    TreeNode *connector(TreeNode *root)
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = find_last_right(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
};
int32_t main()
{
    fast;

    // your code here

    return 0;
}
/*
class Solution
{
private:
    TreeNode *find(TreeNode *Node)
    {
        if (Node->left == NULL)
            return Node;
        else
            return find(Node->left);
    }

    TreeNode *helper(TreeNode *Node)
    {
        if (Node->left == NULL)
            return Node->right;
        else if (Node->right == NULL)
            return Node->left;
        TreeNode *left_child = Node->left;
        TreeNode *far_left = find(Node->right);
        far_left->left = left_child;
        return Node->right;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        else if (root->val == key)
            return helper(root);
        TreeNode *temp = root;
        while (temp)
        {
            if (temp->val > key)
            {
                if (temp->left != NULL && temp->left->val == key)
                {
                    temp->left = helper(temp->left);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right != NULL && temp->right->val == key)
                {
                    temp->right = helper(temp->right);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};
*/