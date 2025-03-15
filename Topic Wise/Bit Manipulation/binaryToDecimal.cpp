#include <bits/stdc++.h>

using namespace std;

int main()
{
    string res = "1001";
    int num = 0;
    int p2 = 1;

    for(int i = res.size()-1;i>=0;i--)
    {
        if(res[i]=='1')
        {
            num = num+p2;
        }
        p2 = p2 * 2;
    }
    cout << num << endl;

    return 0;
}