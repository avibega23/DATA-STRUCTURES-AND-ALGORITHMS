#include <bits/stdc++.h>
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    sort(a.begin(),a.end());
    int maxCnt = -1;
    int cnt = 1;
    for(int i =0;i < a.size();i++)
    {
        if(a[i+1]-a[i]==1)
        {
            cnt++;
        }
        else if(a[i+1]-a[i]==0)
        {
            continue;
        }
        else
        {
            maxCnt = max(cnt,maxCnt);
            cnt = 1;
        }
    }
    return maxCnt;

}