#include<bits/stdc++.h>
using namespace std;

int main()
{
	 vector<int>arr = {3,1,2,4,6,5};
     for(int i = 1;i<arr.size();i++)
     {
        int j = i;
        while(j>=i)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j-1],arr[j]);
            }
            j--;
        }
     }
     for(auto it:arr)
     {
        cout << it << " ";
     }
	return 0;
}