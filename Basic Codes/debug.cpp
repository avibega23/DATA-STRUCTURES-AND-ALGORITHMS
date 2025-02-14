 #include <bits/stdc++.h>
using namespace std;
 int maximumSum(vector<int>& nums) {
        vector<pair<int,int>>hash;

        for(int i = 0;i < nums.size() ; i++)
        {
            int num = nums[i];
            int sum = 0;
            while(num > 0)
            {
                int dig = num % 10;
                num = num/10;
                
                sum += dig;
            }
            hash.push_back({sum,nums[i]});
        }

        int maxi = -1;
        sort(hash.begin(),hash.end());

        for(int i = 1; i < hash.size(); i++)
        {
            int currDigit = hash[i].first;
            int prevDigit = hash[i-1].first;

            if(currDigit==prevDigit)
            {
                int maxSum =  hash[i].second+hash[i-1].second ;
                maxi = max(maxi,maxSum);
            }
        }
        return maxi;

    }

   int main()
   {
   	vector<int> nums = {10,12,19,14};
   	cout << maximumSum(nums);
   }