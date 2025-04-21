#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(n--)
    {
        int a,b,c;
        int cnt = 0;
        cin >> a >> b >> c;
        while(a<=c)
        {
            b += a;
            a += b;
            cnt += 2;
        }
        cout << cnt << endl;
    }

    return 0;
}