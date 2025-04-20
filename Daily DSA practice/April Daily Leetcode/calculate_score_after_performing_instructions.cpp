class Solution {
    public:
        long long calculateScore(vector<string>& instructions, vector<int>& values) {
            vector<bool>hash(values.size(),false);
            long long sum = 0;
            int i = 0;
            while(i < values.size())
                {
                    if(instructions[i]=="add" && hash[i] == false)
                    {
                        sum += values[i];
                        hash[i] = true;
                        i++;
                    }
                    else if(instructions[i]=="jump" && hash[i]==false)
                    {
                        hash[i] = true;
                        i = i + values[i];
                    }
                    else
                    {
                        break;
                    }
                }
            return sum;
        }
    };©leetcode