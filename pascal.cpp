#include <bits/stdc++.h>
using namespace std;

int funtionNcR(int n,int r)
{
    int sum = 1;
    for (int i = 0; i < r; i++)
    {
        sum *= n - i;
        sum /= i + 1;
    }
    return sum;
}

int main()
{
    int r;
    cin >> r ;
    for(int i = 1; i<=r;i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << funtionNcR(i-1,j-1) << " ";
        }
        cout << endl;
    }
    
    return 0;
}