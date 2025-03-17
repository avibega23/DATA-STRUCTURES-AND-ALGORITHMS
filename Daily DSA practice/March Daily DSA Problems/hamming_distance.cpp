class Solution {
    public:
        int hammingDistance(int start, int goal) {
            int cnt = 0;
            while(start>0||goal>0)
            {
                int bit1 = start & 1;
                int bit2 = goal & 1;
                cnt += (bit1 != bit2)?1:0;
                start = start>>1;
                goal = goal>>1;
            }
            return cnt;
        }
    };