#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int cnt = 1;
        int number = n%10;
        cnt *= ((number)-1)*10;

        int sum = 1;
        while(n!=0)
        {
            cnt += sum;
            n /=10;
            sum += 1;
        }
        cout << cnt << endl;
    }
    


    return 0;
}