#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,times;
    cin >> n >> times;

    while(times--)
    {
        if(n%10==0)
        {
            n/=10;
        }
        else
        {
            n-=1;
        }
    }
    cout << n;

    return 0;
}