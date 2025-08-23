class Solution {
    public:
        int numberOfArrays(vector<int>& differences, long long lower, long long upper) {
            long long maxi = 0,mini = 0;
            long long sum = 0;
            for(auto it:differences)
            {
                sum += it;
                maxi = max(maxi,sum);
                mini = min(mini,sum);
            }
            return max(1LL * 0,((upper-maxi) - (lower -mini) +1));
        }
    };