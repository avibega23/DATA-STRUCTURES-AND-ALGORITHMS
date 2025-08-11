#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second


int32_t main() {
    int n1;
    int m1;
    cout << "Enter The Number Of Rows Of First Matrix: ";
    cin >> n1;
    cout << endl;
    cout << "Enter Number Of Columns Of First Matrix: ";
    cin >> m1;
    cout << endl;
    cout << endl;
    cout << "Enter The Elements of First matrix" << endl;

    vector<vector<int>>matrix1(n1,vector<int>(m1));
    for(int i = 0;i<n1;i++)
    {
        cout << "Enter " << i + 1 << "th Row: ";
        for(int j = 0;j<m1;j++)
        {
            cin >> matrix1[i][j];
        }
        cout << endl;
    }
    cout << endl;

    int n2 = m1;
    int m2;
    cout << endl;
    cout << "Enter The Number Of Columns Of Second Matrix: ";
    cin >> m2;
    cout << endl;
    cout << endl;
    vector<vector<int>>matrix2(n2,vector<int>(m2,0));


    cout << "Enter Elements Of Second Matrix";
    cout << endl;
    for(int i = 0;i<n2;i++)
    {
        cout << "Enter " << i + 1 << "th Row: ";
        for(int j = 0;j<m2;j++)
        {
            cin >> matrix1[i][j];
        }
        cout << endl;
    }

    vector<vector<int>>result(n1,vector<int>(m2));

    
    

    return 0;
}