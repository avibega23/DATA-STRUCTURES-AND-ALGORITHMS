class Solution {
    public:
        int trap(vector<int>& arr) {
            int l = 0,r = arr.size()-1,total = 0;
            int lMax = 0;int rMax = 0;
    
            while(l!=r)
            {
                if(arr[l]<=arr[r])
                {
                    if(lMax > arr[l])
                        total += lMax - arr[l];
                    else
                        lMax = arr[l];
                    l++;
                    
                }
                else
                {
                    if(rMax > arr[r])
                        total += rMax - arr[r];
                    else
                        rMax = arr[r];
                    r--;
                }
            }
            return total;
        }
    };