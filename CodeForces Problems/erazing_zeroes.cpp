#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // cin.ignore();
    while(n--)
    {
        int cnt = 0;
        string s;


        cin >> s;
        int i = 0;
        while(i < s.size())
        {
            if(s[i]=='1')
            {
                int j = i+1;
                while(j < s.size() && s[j]!='1')
                {
                    j++;
                }
                if(j<s.size())cnt += j-i-1;
                i = j;
            }
            else
            i++;
        }
        cout << cnt << endl;
    }
    
    
    

    return 0;
}