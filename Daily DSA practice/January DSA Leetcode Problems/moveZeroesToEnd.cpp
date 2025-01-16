class Solution
{
public:
    void pushZerosToEnd(vector<int> &a)
    {
        // code here
        int j = 0;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};