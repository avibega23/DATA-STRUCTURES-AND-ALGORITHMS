#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int h1,h2,m1,m2;
    char c;
    cin >> h1 >> c >> m1;
    cin >> h2 >> c >> m2;
    int min1 = (h1*60)+m1;
    int min2 = (h2*60)+m2;
    int middle = (min1+min2)/2;
    if((middle/60)>9)
    {
        cout << middle/60;
    }
    else
    {
        cout << 0 << middle/60;
    }
    cout << ":";
    if(middle%60>9)
    {
        cout << middle%60;
    }
    else
    {
        cout << 0 << middle%60;
    }


    return 0;
} 