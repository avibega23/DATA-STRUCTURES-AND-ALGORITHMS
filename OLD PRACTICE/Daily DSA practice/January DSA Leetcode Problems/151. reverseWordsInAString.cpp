int left = 0;
int right = s.length() - 1;

while (left <= right && s[left] == ' ')
    left++;
while (left <= right && s[right] == ' ')
    right--;

string ans = "";
string temp = "";

while (left <= right)
{
    char ch = s[left];
    if (ch != ' ')
    {
        temp += ch;
    }
    else if (ch == ' ' && !temp.empty())
    {
        if (ans != "")
        {
            ans = temp + " " + ans;
        }
        else
            ans = temp;
        temp = "";
    }
    left++;
}
if (temp != "")
{
    if (ans != "")
    {
        ans = temp + " " + ans;
    }
    else
    {
        ans = temp;
    }
}
return ans;