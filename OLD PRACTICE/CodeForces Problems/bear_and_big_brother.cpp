#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin >> a >> b;

    int cnt = 0;
    for(int i = 0;i<INT_MAX;i++)
    {
        if(a<=b)
        {
            cnt++;
            a *= 3;
            b *= 2;
        }
        else
        {
            break;
        }
    }
    cout << cnt;    
    

    return 0;
}