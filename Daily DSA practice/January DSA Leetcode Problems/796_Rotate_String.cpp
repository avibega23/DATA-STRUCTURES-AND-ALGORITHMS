class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[0];
            s.erase(0, 1);
            s += ch;
            if (s == goal)
                return true;
        }
        return false;
    }
};
class Solution
{
public:
    bool rotateString(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        string doubled = s1 + s1;
        if (doubled.find(s2) == string::npos)
            return false;
        return true;
    }
};