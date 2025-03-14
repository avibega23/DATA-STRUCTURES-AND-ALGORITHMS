#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, l, c, d, p, nl, np;
	cin >> n;
	cin >> k;
	cin >> l;
	cin >> c;
	cin >> d;
	cin >> p;
	cin >> nl;
	cin >> np;

	int res1 = ((k*l)/nl)/n;
	int res2 = (c*d)/n;
	int res3 = (p/np)/n;
	int finalRes = min(res1,min(res2,res3));
	cout << finalRes;
}