class Solution {
    public:
      long long solve(vector<int>& bt) {
          //your code goes here
          sort(bt.begin(),bt.end());
          int ans = 0;
          int sum = 0;
          for(auto it:bt)
          {
            sum+= ans;
            ans+=it;
          }
          return sum/bt.size();
      }
  };