class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int>mpp;
            for(int i = 0;i<answers.size();i++)
            {
                mpp[answers[i]]++;
            }
            int sum = 0;
            for(auto it:mpp)
            {
                int group = ceil((double)it.second/(it.first+1));
                sum += group * (it.first+1);
            }
            return sum;
        }
    };