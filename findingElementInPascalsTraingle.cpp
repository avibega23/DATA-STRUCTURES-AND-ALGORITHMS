#include <bits/stdc++.h>
using namespace std;

int funtionNcR(int n, int r)
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
    int r, c;
    cin >> r >> c;
    int i = funtionNcR(r - 1, c - 1);
    cout << i << endl;
    return 0;
}