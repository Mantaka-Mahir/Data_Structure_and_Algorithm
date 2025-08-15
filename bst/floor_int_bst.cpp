#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

// problem link:https://www.geeksforgeeks.org/problems/floor-in-bst/1
// time complexity:
// space complexity:
// Function to search a node in BST.
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
class Solution
{

public:
    int floor(Node *root, int x)
    {
        // Code here
        Node *temp = root;
        int floor = -1;
        while (temp)
        {
            if (temp->data == x)
            {
                floor = temp->data;
                return floor;
            }
            else if (temp->data > x)
            {
                temp = temp->left;
            }
            else
            {
                floor = temp->data;
                temp = temp->right;
            }
        }
        return floor;
    }
};

int32_t main()
{
    fast;

    // your code here

    return 0;
}