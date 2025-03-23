#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums = {1,2,3,2,1,5,6,7};
	stack<int>st;
	int n = nums.size();
	vector<int>ans(n,0);
	for(int i = n-1;i>=0;i--)
	{
		while(!st.empty()&&nums[i]>=st.top())
		{
			st.pop();
		}
		if(st.empty())
		{
			
			ans[i] = -1;
		}
		else
		{
			ans[i] = st.top();
		}
		st.push(nums[i]);
	}

	for(auto it:ans)
	{
		cout << it << " ";
	}
	return 0; 
}