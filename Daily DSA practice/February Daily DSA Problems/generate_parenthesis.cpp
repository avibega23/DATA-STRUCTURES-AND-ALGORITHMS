class Solution
{
public:
    void helper(int n, int oc, int cc, string s, vector<string> &ans)
    {
        if (oc == n && cc == oc)
        {
            ans.push_back(s);
            return;
        }
        if (oc < n)
        {
            helper(n, oc + 1, cc, s + '(', ans);
        }
        if (cc < oc)
        {
            helper(n, oc, cc + 1, s + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int oc = 0;
        int cc = 0;
        string s = "";
        vector<string> ans;
        helper(n, oc, cc, s, ans);

        return ans;
    }
};