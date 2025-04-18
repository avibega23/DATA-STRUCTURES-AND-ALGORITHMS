string preToPost(string s) {
    int n = s.size();
  int i = n-1;
  stack<string>st;
  
  while(i>=0)
  {
      if((s[i]>='A' && s[i] <= 'Z')
          ||s[i] >= 'a' && s[i] <= 'z'
          ||s[i] >= '0' && s[i] <= '9'
      )
      {
          string str(1,s[i]);
          st.push(str);
      }
      else
      {
          string t1 = st.top();
          st.pop();
          string t2 = st.top();
          st.pop();
          
          string curr = t1 + t2 +s[i];
          st.push(curr);
      }
      i--;
  }
  return st.top();
}