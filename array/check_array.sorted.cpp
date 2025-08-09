#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
// problem link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// brute force would be to make all possible then check time complexity o(N^2) O(1)
// optimal solution : is to take concept of sliding window : like store copy of the array at last two copy and then window method
// to find non decedning order if the order count == size then there is if not then there is not
// time complexity o(n) and spaec o(n) too
// to get better space complexity we need to do (i%n) while traversing so that we need not to ceate another array (loop would run till 2*n)
// O(n) and O(1)
// edge case array size==1 then return true
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        int count = 1;
        for (int i = 1; i < n * 2; i++)
        {
            if (nums[(i - 1) % n] <= nums[i % n])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count == n)
                return true;
        }
        return false;
    }
};

int32_t main()
{
    fast;

    // your code here

    return 0;
}