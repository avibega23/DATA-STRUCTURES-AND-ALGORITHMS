class Solution {
    public:
        void helper(vector<char>&s,int i)
        {
            if(i >= s.size())
            {
                return;
            }
            char ch = s[i];
            helper(s,i+1);
            s[-(i-(s.size()-1))] = ch;
            return;
        }
        void reverseString(vector<char>& s) {
            helper(s,0);
        }
    };