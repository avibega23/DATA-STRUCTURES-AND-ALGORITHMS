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
    	int n,k;
    	cin >> n >> k;

 		vector<int>arr(n);
 		for(int i = 0;i<n;i++)
 		{
 			cin >> arr[i];
 		}
 		vector<int>temp = arr;
 		sort(temp.begin(),temp.end());

 		if(arr == temp)
 		{
 			cout << "YES" << endl;
 			continue;
 		}
 		if(k == 1)
 		{
 			cout << "NO" << endl;
 			continue;
 		}
 		if(k>=2) cout << "YES" << endl;

    }
    return 0;
}
