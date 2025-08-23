#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k,n,w;
    int sum = 0;
    cin >> k >> n >> w;
    for(int i = 1;i<=w;i++)
    {
        sum += (i*k);
    }
    if(sum-n<=0)
    {
        cout << 0;
    }
    else
    cout << sum-n;
    

    return 0;
}