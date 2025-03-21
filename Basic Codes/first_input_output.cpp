#include<bits/stdc++.h>
using namespace std;

class Q{
private:
	int arr[4];
	int currSize = 0;
	int start = -1;
	int end = -1;
	int a = 4;

public:

	void push(int x)
	{
		if(currSize == 0)
		{
			start = end = 0;
		}
		else
		{
			end = (end+1)%a;
		}
		arr[end] = x;
		
		currSize++;
	}
	int pop()
	{
		if(currSize == 0) return -1;
		int el = arr[start];
		if(currSize == 1)
		{
			start = end = -1;
		}
		else
		{
			start = (start+1)%a;
		}
		currSize -= 1;
		return el;
	}
	int top()
	{
		if(currSize == 0) return -1;
		else
		{
			return arr[start];
		}
	}
	int size()
	{
		return currSize;
	}
};
int main()
{
	Q queue;
	queue.push(5);
	queue.push(6);
	queue.push(9);
	cout << queue.top();
}