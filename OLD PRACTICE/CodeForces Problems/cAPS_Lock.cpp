#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    bool allUpper = true;
    bool exceptFirst = true;
    if(s.size()==1)
    {
        if(isupper(s[0]))
        {
            s[0] = tolower(s[0]);
        }
        else
        {
            s[0] = toupper(s[0]);
        }
        cout << s << endl;
        return 0;
    }
    for(int i = 0;i<s.size();i++)
    {
        if(!isupper(s[i])) allUpper = false;
        if(i>0 && !isupper(s[i])) exceptFirst = false; 
    }
    if(allUpper || exceptFirst)
    {
        for(int i = 0;i<s.size();i++)
        {
            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s[i] = toupper(s[i]);
            }
        }
        cout << s << endl;
        return 0;
    }
    cout << s;
    return 0;
}#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    bool allUpper = true;
    bool exceptFirst = true;
    if(s.size()==1)
    {
        if(isupper(s[0]))
        {
            s[0] = tolower(s[0]);
        }
        else
        {
            s[0] = toupper(s[0]);
        }
        cout << s << endl;
        return 0;
    }
    for(int i = 0;i<s.size();i++)
    {
        if(!isupper(s[i])) allUpper = false;
        if(i>0 && !isupper(s[i])) exceptFirst = false; 
    }
    if(allUpper || exceptFirst)
    {
        for(int i = 0;i<s.size();i++)
        {
            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s[i] = toupper(s[i]);
            }
        }
        cout << s << endl;
        return 0;
    }
    cout << s;
    return 0;
}