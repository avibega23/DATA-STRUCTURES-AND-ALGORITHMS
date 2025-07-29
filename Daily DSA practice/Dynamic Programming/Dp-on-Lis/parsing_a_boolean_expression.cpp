//https://leetcode.com/problems/parsing-a-boolean-expression/description/


class Solution {
public:
    bool parse_not(string s)
    {
        return (s[0] == 'f') ? true : false;        
    }
    bool parse_or(string s)
    {
        if(s.size() == 1) return (s[0]=='f') ? false : true;
        bool ans = (s[0] == 'f') ? false : true;
        for(int i = 1;i<s.size();i++)
        {
            if(s[i]=='f') ans |= false;
            else ans |= true;
        }
        return ans;
    }
    bool parse_and(string s)
    {
        if(s.size() == 1) return (s[0]=='f') ? false : true;
        bool ans = (s[0] == 'f') ? false : true;
        for(int i = 1;i<s.size();i++)
        {
            if(s[i]=='f') ans &= false;
            else ans &= true;
        }
        return ans;
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        string a = "";
        for(auto it:expression)
        {
            if(it == ',') continue;
            a.push_back(it);
        }
        expression  = a;
        for(auto it:expression)
        {
            st.push(it);
            if(st.top() == ')')
            {
                st.pop();
                string ans   = "";
                while(st.top()!='(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
                if(st.top()=='&')
                {
                    st.pop();
                    if(parse_and(ans)==true) st.push('t');
                    else st.push('f');
                    cout << parse_and(ans);
                }
                else if(st.top()=='|')
                {
                    st.pop();
                    if(parse_or(ans)==true) st.push('t');
                    else st.push('f');
                    cout << parse_or(ans);
                }
                else
                {
                    st.pop();
                    if(parse_not(ans)==true) st.push('t');
                    else st.push('f');
                }
            }
        }
        return (st.top()=='f')?false:true;
    }
};
