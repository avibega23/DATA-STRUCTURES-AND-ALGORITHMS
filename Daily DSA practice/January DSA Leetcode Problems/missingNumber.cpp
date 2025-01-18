#include <bits/stdc++.h>
int missingNumber(vector<int> &a, int N)
{
    // Write your code here.
    int xor2 = 0, xor1 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return (xor1 ^ xor2);
}