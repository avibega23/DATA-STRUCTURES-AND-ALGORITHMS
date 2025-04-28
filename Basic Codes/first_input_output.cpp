    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin >> t;
        
       int n = 789658964;
       int ans = 0;
       while(n!=0)
       {
        int rem = n%10;
        ans = (ans*10) + rem;
        n /= 10;
       }
        cout << ans;

        return 0;
    }