#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<char>>mat(n,vector<char>(m));
        for(int i = 0;i<mat.size();i++)
        {
            for(int j = 0;j<mat[0].size();j++)
            {
                cin >> mat[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(mat[i][m-1]=='R')cnt++;
        }
        for(int i = 0;i<m-1;i++)
        {
            if(mat[n-1][i]=='D') cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}