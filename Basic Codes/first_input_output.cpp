    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin >> t;
        
        while(t--)
        {
            long long a,b,c;
            cin >> a >> b >> c;
           if(a < c)
           {
            cout << 1 << " ";
           }
           else
           {
            cout << -1 << " ";
           }
           if(b*a > c)
           {
            cout << b;
           }
           else
           {
            cout << -1;
           }
           cout << endl;
        }
        

        return 0;
    }