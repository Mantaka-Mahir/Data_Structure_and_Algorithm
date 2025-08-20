#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
// problem link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// time complexity: O(h) → h is the height of the BST (O(log n) for balanced, O(n) for skewed tree)
// space complexity: O(1) → uses only a few variables, no recursion or extra data structures

struct Node
{
    int data;
    struct Node *left;   
    struct Node *right;
};

int findCeil(Node *root, int input)
{
    // Your code here
    Node *temp = root;
    int ceil = -1;
    while (temp)
    {
        if (temp->data == input)
        {
            ceil = temp->data;
            return ceil;
        }
        if (temp->data < input)
        {
            temp = temp->right;
        }
        else
        {
            ceil = temp->data;
            temp = temp->left;
        }
    }
    return ceil;
}
int32_t main()
{
    fast;

    // your code here

    return 0;
}