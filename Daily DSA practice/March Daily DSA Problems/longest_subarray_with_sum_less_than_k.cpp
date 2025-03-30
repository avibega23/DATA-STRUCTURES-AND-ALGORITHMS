#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<int>arr = {2,5,6,5,4,4,4,3,2,4};
   int k  = 14;
   int l = 0;
   int r = 0;
   int maxLen = 0;
   int sum = 0;
   while(r<arr.size())
   {
        sum += arr[r];
        if(sum<=k)
        {
            maxLen = max(maxLen,r-l+1);
        }
        else
        {
            sum-=arr[l];
            l++;

        }
        r++;
   }
   cout << maxLen << endl;
   return 0;
}