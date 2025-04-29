    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin >> n;
        int temp = n;
        int cnt = 0;
        for(int i = 1;i<=n;i++)
        {
            if(i == 1 || i == n)
            {
                cnt += temp;
            }
            else
            {
                cnt += ((temp-1)*i)+1;
            }
            temp--;
        }
        cout << cnt;        
        return 0;
    }