#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<string,int> mpp = {
		{"Tetrahedron",4},
		{"Cube",6},
		{"Octahedron",8},
		{"Dodecahedron",12},
		{"Icosahedron",20},
	};
	int testcase;
	cin >> testcase;
	int sum = 0;
	for(int i = 0;i<testcase;i++)
	{
		string s ;
		cin >> s;
		sum+= mpp[s];
	}
	cout << sum << endl;

}