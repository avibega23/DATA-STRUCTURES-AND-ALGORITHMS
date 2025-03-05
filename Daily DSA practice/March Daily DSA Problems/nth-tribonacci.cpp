class Solution {
    public:
        int helper(int n,vector<int>&arr)
        {
            if(n==0) return 0;
            if(n==1||n==2) return 1;
            if(arr[n]!=-1) return arr[n];
    
            return arr[n] = helper(n-1,arr)+helper(n-2,arr)+helper(n-3,arr);
         }
        int tribonacci(int n) {
            vector<int> arr(n+1,-1);
            return helper(n,arr);
        }
    };