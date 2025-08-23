#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int maxLen = 0;
    int i = 0;
    int j = 0;
    unordered_map<char,int>mpp;
    while(j < str.size())
    {
        mpp[str[j]]++;
        while(mpp.size()>k)
        {
            mpp[str[i]]--;
            if(mpp[str[i]]==0)
            {
                mpp.erase(str[i]);
            }
            i++;
        }
        if(mpp.size()<=k)
        {
            maxLen = max(maxLen,j-i+1);
        }
        j++;
    }
    return maxLen;
}


