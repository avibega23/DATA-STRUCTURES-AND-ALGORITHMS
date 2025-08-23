#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char,int>mpp;

    string s;
    getline(cin,s);

    for(int i = 0;i<s.size();i++)
    {
        mpp[s[i]]++;
    }
    
    if(mpp.size()%2==0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }

    return 0;
}