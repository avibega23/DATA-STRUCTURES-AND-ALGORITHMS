https://codeforces.com/problemset/problem/1896/A
    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define endl '\n'
    #define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

    int32_t main() {
        fast_io

        // Your code here
        int t;
        cin >> t;
        while(t--)
        {
            int n;
            cin >> n;
            vector<int>arr(n);
            for(int i = 0;i<n;i++)
            {
                cin >> arr[i];
            }

            if(arr[0]!=1)cout << "NO" << endl;
            else cout << "YES" << endl;
        }

        return 0;
    }
