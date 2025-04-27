    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char,int>mpp;

        for(auto it:s)
        {
            mpp[it]++;
        }
        for(auto it:mpp)
        {
            if(it.second % n != 0)
            {
              cout << -1 << endl;
              return 0;  
            } 
        }
        string ans = "";
        for(auto it:mpp)
        {
            int num = it.second/n;
            for(int i = 0;i<num;i++)
            {
                ans += it.first;
            }
        }
        string newAns = "";
        for(int i = 0;i<n;i++)
        {
            newAns += ans;
        }
        cout << newAns;
        return 0;
    }