#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);

    int first = 0;
    int second = 0;
    int fH = 0;
    int sH = 0;
    for(int i = s1.size()-2;i<s1.size();i++)
    {
        first = first*10+(s1[i]-'0');
        fH = fH*10+(s1[i-3]-'0');
        second = second*10+(s2[i]-'0');
        sH = sH*10+(s2[i-3]-'0');
    }
    int average;
    int sAverage = (fH+sH)/2;
    if(first == 0 && second == 0) average = 30;
    else
    {
        average = (first+second)/2;
    }
    int j = s1.size()-1;
    while(average != 0)
    {
        int rem = average%10;
        average/=10;
        s1[j] = '0'+rem;
        j--;
    }
    j = 1;
    while(sAverage != 0)
    {
        int rem = sAverage%10;
        sAverage/=10;
        s1[j] = '0'+rem;
        j--;
    }
    cout << s1 << endl;
    return 0;
}