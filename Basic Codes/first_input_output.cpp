#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    int i = 0;
    while(i<n)
    {
        string s;
        getline(cin,s);
        for(int i = 0;i<s.size();i++)
        {
            if(i == 0) cout << s[i];
            if(s[i-1] == ' ') cout << s[i];
        }
        cout << endl;
        i++;
    }
    

    return 0;
}