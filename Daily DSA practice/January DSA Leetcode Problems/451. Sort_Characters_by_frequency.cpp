class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto it:s) freq[it]++;

        // map<char,int>freq;
        // for(auto it:s) freq[it]++;

        // vector<pair<char,int>> freqAns;
        // for(auto [ch,it]:freq) freqAns.push_back({ch,it});

        // auto cmp = [&](pair<char,int>&a,pair<char,int>&b)
        // {
        //     return a.second > b.second;
        // };

        // sort(freqAns.begin(),freqAns.end(),cmp);

        vector<vector<char>> bucket(s.length()+1);
        for(auto[ch,it]:freq) bucket[it].push_back(ch);


        string ans = "";

        for(int i = bucket.size()-1;i>=1;i--)
        {
            for(auto ch:bucket[i])ans.append(i,ch);
        }

        return ans;
    }
};