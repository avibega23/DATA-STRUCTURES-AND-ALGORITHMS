class Solution {
    public:
      int solve(int num)
      {
          if(num%4==1)return 1;
          else if(num%4==2)return num+1;
          else if(num%4==3)return 0;
          else return num;
      }
      int findXOR(int l, int r) {
          return solve(l-1)^solve(r);
          // complete the function here
      }
  };