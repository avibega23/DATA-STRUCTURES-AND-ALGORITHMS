#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n = 567 ;
	
	int ans = 0;
	while(n!=0)
	{
		int mod = n%10;
		ans += (ans*10)+mod;
	}
	cout << ans << endl;
}