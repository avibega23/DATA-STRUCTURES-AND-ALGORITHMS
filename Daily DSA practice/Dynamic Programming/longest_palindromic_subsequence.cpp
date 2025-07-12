//recursive solution
class Solution {
public: 
    void recurse(int &maxi,int ind,string &s,string ans)
    {
        string temp = ans;
        reverse(temp.begin(),temp.end());
        int n = ans.size();
        if(temp==ans) maxi = max(maxi,n);
        if(ind==s.size()) return;

        recurse(maxi,ind+1,s,ans+s[ind]);
        recurse(maxi,ind+1,s,ans);
    }
    int longestPalindromeSubseq(string s) {
        int maxi = 0;
        recurse(maxi,0,s,"");
        return maxi;
    }
};

//
