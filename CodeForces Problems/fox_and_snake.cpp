#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	bool check  = true;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int i = 0;i<m;i++)
			{
				cout << "#";
			}
			cout << '\n';
		}
		else
		{
			int done = false;
			for(int i = 0;i<m;i++)
			{
				
				if(i == m-1 && check && !done)
				{
					cout << "#";
					check = false;
					done = true;
				}
				else if(i == 0 && !check && !done)
				{
					cout << "#";
					check = true;
					done = true;
				}
				else
				{
					cout << ".";
				}
			}
			cout << '\n';
		}
	}
}