#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        string has,pass;
        cin >> pass >> has;

        if(has.size()<pass.size())
        {
            cout << "NO" << endl;
        }
        else
        {
            string ans = "NO";
            unordered_map<char,int>passHash,hashHash;
            for(auto it:pass)
            {
                passHash[it]++;
            }

            int i = 0,j = 0;
            while(j<pass.size())
            {
                hashHash[has[j]]++;
                j++;
            }
            if(passHash == hashHash)
            {
                ans = "YES";
            }
            else
            {
                while(j < has.size())
                {
                    hashHash[has[i]]--;
                    if(hashHash[has[i]]==0) hashHash.erase(has[i]);
                    hashHash[has[j]]++;
                    i++;
                    j++;
                    if(passHash == hashHash)
                    {
                        ans = "YES";
                        break;
                    }
                }
            }
            cout << ans << endl;
        } 
        
    }

    return 0;
}