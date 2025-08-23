class Solution {
    public:
      void sieve() {}
  
      vector<int> findPrimeFactors(int N) {
          // Write your code here
          vector<int>ans(N+1);
          for(int i = 1;i<=N;i++)
          {
              ans[i] = i;
          }
          for(int i = 2;i*i<=N;i++)
          {
              if(ans[i]==i)
              {
                  for(int j = i*i;j<=N;j+=i)
                  {
                      if(ans[j]==j)
                          ans[j] = i;
                  }
              }
          }
          vector<int>mainAns;
          while(N>1)
          {
              mainAns.push_back(ans[N]);
              N = N / ans[N];
          }
          return mainAns;
      }
  };