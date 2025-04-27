#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    string s;
    cin >> s;
    unordered_map<char,int>mpp;
    for(int i = 0;i<s.size();i++)
    {
        mpp[s[i]]++;
    }
    int maxi = mpp[s[0]];
    for(auto it:mpp)
    {
        if(it.second != maxi)
        {
            cout << -1 << endl;
            return 0;
        }
    }
     vector<char> chars;
    for(auto &it : mpp) {
        chars.push_back(it.first);
    }
    sort(chars.begin(), chars.end()); // sorting to maintain order
    
    string ans = "";
    for(int i = 0; i < maxi; i++) {
        for(char c : chars) {
            ans += c;
        }
    }
    cout << ans;
    return 0;
}