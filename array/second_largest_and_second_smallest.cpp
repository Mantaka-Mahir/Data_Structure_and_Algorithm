#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
// problem link :https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array/
int32_t main()
{
    fast;

    // brute force: sort and print (only works when the array has all distinct element) O(N*logN) space O(1)
    // better solution would be run a loop then find max and min and then another loop to find then just smaller or larger than those too o(N) & O(1)
    // optimal solution :
    /*
         just like before but we will use one traversal : (writting for max):
         we keep max and second max we will run loop and find max and then compare with second max O(n) but one loop
    */
    int arr[] = {1, 2, 4, 7, 7, 5};
    int max = INT_MIN;
    int max_2nd = INT_MIN;
    int min = INT_MAX;
    int min_2nd = INT_MAX;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > max)
        {
            max_2nd = max;
            max = arr[i];
        }
        else if (arr[i] > max_2nd && arr[i] != max)
        {
            max_2nd = arr[i];
        }
        if (arr[i] < min)
        {
            min_2nd = min;
            min = arr[i];
        }
        else if (arr[i] < min_2nd && arr[i] != min)
        {
            min_2nd = arr[i];
        }
    }
    cout << max << endl;
    cout << min << endl;
    cout << max_2nd << endl;
    cout << min_2nd << endl;

    return 0;
}