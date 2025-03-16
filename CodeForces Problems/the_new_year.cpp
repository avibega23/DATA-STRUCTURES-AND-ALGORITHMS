#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,z;
	cin >> x >> y >> z;

	int maxEl = max(max(x,y),z);
	int minEl = min(min(x,y),z);
	int sec = x+y+z - maxEl - minEl;

	int sum = 0;
	sum += maxEl - sec ;
	sum += sec-minEl;
	cout << sum;
	return 0;
}