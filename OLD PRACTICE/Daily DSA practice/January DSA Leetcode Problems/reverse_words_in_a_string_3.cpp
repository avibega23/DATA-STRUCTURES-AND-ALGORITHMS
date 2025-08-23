class Solution {
public:
    string reverseWords(string s) {
        s = " " + s +" ";
        string ans = "";
        int index =0;
        for(int i =1;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                int j = i-1;
                while(j>=index)
                {
                    ans += s[j];
                    j--;
                }
                index = i;
            }
        }
        ans.erase(ans.size()-1);
        return ans;

    }
};