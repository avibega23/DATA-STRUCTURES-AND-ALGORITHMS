#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    int n,m;
    cin >> n >> m;
    if(m%n!=0)
    {
        cout << -1;
        return 0;
    }
    if(m == n)
    {
        cout << 0;
        return 0;
    }
    m = m/n;
    while(m>1)
    {
        if(m%2 == 0)
        {
            m /= 2;
            cnt++;
        }
        else if(m%3 == 0)
        {
            m/=3;
            cnt++;  
        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    cout << cnt;

    return 0;
}