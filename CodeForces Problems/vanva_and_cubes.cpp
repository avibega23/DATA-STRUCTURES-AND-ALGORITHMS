#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    int sum = 0;
    int cubes;
    cin >> cubes;

    while(n)
    {
        sum += n;
        if(cubes>=sum)
        {
            cubes -= sum;
        }
        else
        {
            break;
        }
        n++;    
    }
    cout << n-1;


    return 0;
}