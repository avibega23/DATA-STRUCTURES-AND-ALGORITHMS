#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin,s);
    vector<char>nums;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='+')
            continue;
        else
        {
            nums.push_back(s[i]);
        }
    }
    sort(nums.begin(),nums.end());
    s = "";
    for(int i = 0;i<nums.size();i++)
    {
        s += nums[i];
        if(i !=nums.size()-1)
        s += "+";
    }
    cout << s ;

    return 0;
}