#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int mini =ceil(double(n)/2);
    int cnt = -1;
    for(int i = mini;i<=n;i++)
    {
        if(i%m == 0)
        {
            cnt = i;
            break;
        }
    }
    cout << cnt;        
    return 0;
}