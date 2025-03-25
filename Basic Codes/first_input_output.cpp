#include<bits/stdc++.h>
using namespace std;

int main()
{
	 int sum = 0;
	 vector<int>arr = {3,1,2,4};
        for(int i = 0;i<arr.size();i++)
        {
            for(int j = i;j<arr.size();j++)
            {
                vector<int> data(arr.begin()+i,arr.begin()+j);

                int mini = data[0];
                for(int k = 1;k<data.size();k++)
                {
                    mini = min(mini,data[k]);
                }
                sum += mini;
            }
        }
        cout << sum;
	return 0;
}