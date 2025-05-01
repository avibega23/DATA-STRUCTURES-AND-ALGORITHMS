    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n,t;
        cin >> n >> t;
        vector<int>nums(n-1);
        for(int i = 0;i<n-1;i++)
        {
            cin >> nums[i];
        }
        int i = 0;
        while(i<t-1)
        {
           
            i += nums[i];

        }
         if(i == t-1)
        {
            cout << "YES" << endl;
            return 0;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
            }

        return 0;
    }