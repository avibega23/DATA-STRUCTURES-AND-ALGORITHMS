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
    string mainAns = "NO";
    int n = 5;
    while(n--)
    {
        string ans;
        cin >> ans;
        
        // for(int i = 0;i<ans.size();i++)
        // {
        //     if(mpp.find(ans[i])!=mpp.end())
        //     {
        //         mainAns = "YES";
        //         break;
        //     }
        // }
        if(mpp.find(ans[0])!=mpp.end()||mpp.find(ans[1])!=mpp.end())
        {
            mainAns = "YES";
            break;
        }

    }
    cout << mainAns;
    

    return 0;