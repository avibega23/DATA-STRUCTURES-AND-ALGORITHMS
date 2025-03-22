//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int priority(char i)
    {
        if(i == '^') return 3;
        else if(i=='*'||i=='/')return 2;
        else if(i == '+'||i == '-') return 1;
        else return 0;
    }
    string preToInfix(string s) {
        // Write your code here
        reverse(s.begin(),s.end());
        int i = 0;
        stack<int>st;
        string ans = "";
        for(auto it:s)
        {
            if(it == ')')
            {
                it = '(';
            }
            else if(it == '(')
            {
                it = ')';
            }
        }
        while(i<s.size())
        {
            if((s[i]>='A' && s[i] <= 'Z')
                ||s[i] >= 'a' && s[i] <= 'z'
                ||s[i] >= '0' && s[i] <= '9'
            )
                ans+=s[i];
            else if(s[i] == '(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    ans+= st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if(s[i]=='^')
                {
                    while(!st.empty()&&priority(s[i])<=priority(st.top()))
                    {
                        if (s[i] == '^' && st.top() == '^') break;
                        ans+=st.top();
                        st.pop();
                    }
                }
                else
                {
                    while(!st.empty()&&priority(s[i])<priority(st.top()))
                    {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends