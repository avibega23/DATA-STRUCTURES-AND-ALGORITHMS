#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 1;i<=11;i++)
    {
        if(i == 1 || i == 6 || i == 11)
        {
            for(int j = 1;j<=11;j++)
            {
                if(j==1||j==6||j==11)
                {
                    if(j == 11)
                    {
                        cout << "+";
                    }
                    else
                    cout << "+ ";
                }
                else
                {
                    cout << "- ";
                }
            }
        }
        else
        {
            for(int j = 1;j<=11;j++)
            {
                if(j == 1||j ==6||j==11)
                {
                    if(i == 11)
                    {
                        cout << "|";
                    }
                    else
                    cout << "| ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}