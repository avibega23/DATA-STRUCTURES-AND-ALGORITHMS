//https://codeforces.com/problemset/problem/1901/A
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
    	int n,x;
    	cin >> n >> x;

 		vector<int>arr(n);
 		for(int i = 0;i<n;i++)
 		{
 			cin >> arr[i];
 		}
 		int maxi = 0;
 		for(int i = 0;i<n;i++)
 		{
 			if(i == 0) maxi = max(maxi,arr[i]);	
 			if(i == n-1) maxi = max(maxi,(x-arr[i])*2);
 			else maxi = max(maxi,arr[i+1]-arr[i]);
 		}
 		cout << maxi << endl;
    }
    return 0;
}


