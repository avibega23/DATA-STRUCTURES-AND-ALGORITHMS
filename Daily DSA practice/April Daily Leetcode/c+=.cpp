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
        while(a<=c && b<=c)
        {
            if(a>=b)
            {
                b+=a;
            }
            else
            {
                a+=b;
            }
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}