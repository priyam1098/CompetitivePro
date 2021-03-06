/*
Given an array A[], for each element in the array, the task is to find the sum of all the previous elements which are strictly greater than the current element.

Examples:

Input: A[] = {2, 6, 4, 1, 7}
Output: 0 0 6 12 0
Explanation: 
For 2 and 6 there is no element greater to it on the left.
For 4 there is 6.
For 1 the sum would be 12.
For 7 there is again no element greater to it.

Input: A[] = {7, 3, 6, 2, 1}
Output: 0 7 7 16 18
Explanation: 
For 7 there is no element greater to it on the left. 
For 3 there is 7.
For 6 the sum would be 7.
For 2 it has to be 7 + 3 + 6 = 16.
For 1 the sum would be 7 + 3 + 6 + 2 = 18

Using Fenwick Tree:

Traverse the given array and find the sum(say total_sum) of all the elements stored in the Fenwick Tree.
Now Consider each element(say arr[i]) as the index of the Fenwick Tree.
Now find the sum of all the elements(say curr_sum) which is smaller than the current element using values stored in Tree.
The value of total_sum – curr_sum will give the sum of all elements which are strictly greater than the elements on the left side of the current element.
Update the current element in the Fenwick Tree.
Repeat the above steps for all the elements in the array.

Source: GFG
*/

// Time Complexity: O(N * log(max_element))
// Auxiliary Space: O(max_element)

#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1000000;
 
// Init Fenwick Tree
int Bit[maxn + 5];
 
void sum(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int index;
        int total_sum = 0;
        index = 100000;

        while (index)
        {
            total_sum += Bit[index];
            index -= index & -index;
        }
        int cur_sum = 0;
        index = arr[i];
 
        while (index)
        {
            cur_sum += Bit[index];
            index -= (index & -index);
        }
 
        int ans = total_sum - cur_sum;
        cout << ans << " ";
 
        index = arr[i];
        while (index <= 100000)
        {
            Bit[index] += arr[i];
            index += (index & -index);
        }
    }
}
 
int main()
{
    int ar[] = { 7, 3, 6, 2, 1 };
    int N = sizeof ar / sizeof ar[0];

    sum(ar, N);

    return 0;
}

