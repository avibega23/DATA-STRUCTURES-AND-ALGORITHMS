class Solution {
    public:
      static bool cmp(pair<int,int>p1,pair<int,int>p2)
          {
              double r1 = (double)p1.first/p1.second;
              double r2 = (double)p2.first/p2.second;
              return r1>r2;
          }
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          // code here
          vector<pair<int,int>>pairs(val.size());
          for(int i = 0;i<pairs.size();i++)
          {
              pairs[i] = {val[i],wt[i]};
          }
          
          sort(pairs.begin(),pairs.end(),cmp);
          double sum = 0;
          for(auto it:pairs)
          {
              if(capacity == 0) break;
              if(capacity >= it.second)
              {
                  sum += it.first;
                  capacity -= it.second;
              }
              else
              {
                  double value = ((double)capacity / it.second) * it.first;
                  sum += value;
                  capacity = 0;
              }
          }
          return sum;
          
      }
  };