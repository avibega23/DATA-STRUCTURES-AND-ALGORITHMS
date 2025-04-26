#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.ignore();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int med = 0;
        if(n%2 == 0) med = n/2;
        else med =
        int sum = floor(n/2) + n;
        while(n!=0)
        {
            sum = (sum+n)/2;
            n--;
        }
        cout << sum << endl;
    }

    

    return 0;
}