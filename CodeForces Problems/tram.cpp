#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int maxii = INT_MIN;
    int cnt = 0;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        cnt -= a;
        cnt += b;
        maxii = max(cnt,maxii);
    }
    cout << maxii << endl;
    

    return 0;