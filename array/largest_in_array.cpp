#include <bits/stdc++.h>
using namespace std;
// problem link : https://takeuforward.org/data-structure/find-the-largest-element-in-an-array/
int main()
{ // brute force would be to sort and then print the last index(as it is sorted in ascending order!)
    int arr[] = {2, 5, 1, 3, 0};
    int max = INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
            max = arr[i]; // O(n) approach
    }
    cout << max;
}