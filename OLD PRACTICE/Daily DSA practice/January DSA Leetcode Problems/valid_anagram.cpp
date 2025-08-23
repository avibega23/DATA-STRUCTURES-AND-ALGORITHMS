class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp1;
        if(s.size()!=t.size())return false;
        for(int i = 0;i<s.size();i++)
        {
            mpp1[s[i]]++;
        }
        for(int i = 0;i<s.size();i++)
        {
            mpp1[t[i]]--;
            if(mpp1[t[i]]<0) return false;
        }
        return true;

    }
};