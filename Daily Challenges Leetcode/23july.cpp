//https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2025-07-23


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        pair<int,string> first = {x,"ab"} , second = {y,"ba"};
        if(y>x)
            swap(first,second);
        int total = 0;
        for(auto [p,ss]:{first,second})
        {
            vector<char>st;

            for(auto c:s)
            {
                st.push_back(c);
                if(st.size()>=2 && st.back() == ss[1] && st[st.size()-2] == ss[0])
                {
                    total += p;
                    st.pop_back();
                    st.pop_back();
                }
            }
            string ans = "";
            for(int i = 0;i<st.size();i++)
            {
                ans.push_back(st[i]);
            }
            s = ans;
        }
        return total;
    }
};
