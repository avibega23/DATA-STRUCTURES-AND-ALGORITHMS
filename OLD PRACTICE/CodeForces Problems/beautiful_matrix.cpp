#include<bits/stdc++.h>
using namespace std;

int main()
{
	int row;
	int col;
	vector<vector<int>>mat(5,vector<int>(5));
	for(int i = 0;i<=4;i++)
	{
		for(int j = 0;j<=4;j++)
		{
			cin >> mat[i][j];
			if(mat[i][j]==1)
			{
				row = i+1;
				col = j+1;
			}
		}
	}
	int calc1 = (row>3)?row-3:3-row;

	int calc2 = (col>3)?col-3:3-col;
	
	cout << calc1+calc2;
	return 0;
}