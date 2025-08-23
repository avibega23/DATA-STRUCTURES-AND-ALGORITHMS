#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0]=='1'||s[s.size()-1]=='1')
        {
            cout << s.size()*2 << endl;
        }
        else
        {
            int mainSum = 0;
            for(int i = 0;i<s.size();i++)
            {
                if(s[i]=='1')
                {
                    int left = (i+1)*2;
                    int right = (s.size()-i)*2;
                    int sum = max(left,right);
                    mainSum = max(sum,mainSum);
                }
            }
            int size = s.size();
            mainSum = max(mainSum,size);
            cout << mainSum << endl;
        }
    }
    return 0;
}