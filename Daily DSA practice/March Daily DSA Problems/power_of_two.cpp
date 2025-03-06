class Solution {
    public:
        bool helper(int n)
        {
            if(n==1) return true;
           if(n%2!=0)
           {
            return false;
           }
           if(n==0) return true;
           return helper(n/2);
        }
        bool isPowerOfTwo(int n) {
            if(n<=0) return false;
            return helper(n);
        }
    };