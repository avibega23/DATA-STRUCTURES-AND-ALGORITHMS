#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int>nums(7);
    int sum = 0;
    for(int i = 0;i<7;i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    int rem = t%sum;
    if(rem == 0) rem = sum;

    for(int i = 0;i<nums.size();i++)
    {
        rem -= nums[i];
        if(rem <= 0)
        {
            cout << i+1;
            break;
        }
    }

    return 0;
}