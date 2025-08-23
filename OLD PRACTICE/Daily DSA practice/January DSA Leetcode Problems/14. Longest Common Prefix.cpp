class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        int mini = INT_MAX;
        for (auto it : strs)
        {
            if (it.length() < mini)
            {
                mini = it.length();
            }
        }

        for (int i = 0; i < mini; i++)
        {
            for (auto s : strs)
            {
                if (s[i] != strs[0][i])
                {
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};