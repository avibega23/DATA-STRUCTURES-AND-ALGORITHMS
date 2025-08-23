class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>groupAnagrams;

        for(string word:strs)
        {
            vector<int>freq(26,0);
            for(char ch:word)
            {
                freq[ch-'a']++;
            }

            string key = "";
            for(auto it:freq)
            {
                key += to_string(it)+"#";
            }

            groupAnagrams[key].push_back(word);
        }
        vector<vector<string>>ans;
        for(auto it:groupAnagrams)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};