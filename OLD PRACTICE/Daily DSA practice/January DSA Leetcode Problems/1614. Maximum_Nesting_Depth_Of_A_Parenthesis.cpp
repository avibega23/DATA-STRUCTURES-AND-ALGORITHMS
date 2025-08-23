class Solution {
public:
    int maxDepth(string s) {
        int maxCount = -1;
        int count = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                count++;
            }
            else if(s[i]==')')
            {
                count--;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
}; 