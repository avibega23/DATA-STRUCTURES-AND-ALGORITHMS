Solution {
    public:
      // Function to convert an infix expression to a postfix expression.
      int priority(char i)
      {
          if(i == '^') return 3;
          else if(i=='*'||i=='/')return 2;
          else if(i == '+'||i == '-') return 1;
          else return 0;
      }
      string infixToPostfix(string& s) {
          // Your code here
          int n = s.size();
          stack<char> st;
          string ans = "";
          int i = 0;
          while(i<n)
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
                  while(!st.empty() && priority(s[i])<=priority(st.top()))
                  {
                      ans+=st.top();
                      st.pop();
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
          return ans;
      }
  };