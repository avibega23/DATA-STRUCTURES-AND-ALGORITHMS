#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,first,second;
    cin >> n >> first >> second;
    vector<int>nums(n);
    for(int i = 0;i<nums.size();i++)
    {
        cin >> nums[i];
    }
    for(int i = 0;i<nums.size();i++)
    {
        bool check = true;
        for(int j = i-1;j>=0 && j>=i-first;j--)
        {
            if(nums[i]>=nums[j])
            {
                check = false;
                break;
            }
        }
        if(!check) continue;
        for(int j = i+1;j<nums.size()&&j<=i+second;j++)
        {
            if(nums[i]>=nums[j])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            cout << i+1 << endl;
            return 0;
        } 
    }
    return 0;
}