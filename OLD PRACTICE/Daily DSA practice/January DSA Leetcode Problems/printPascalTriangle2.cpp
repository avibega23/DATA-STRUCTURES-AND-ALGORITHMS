class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        long long ans = 1;
        vector<int> myAns;
        myAns.push_back(ans);
        for (int i = 1; i < rowIndex + 1; i++)
        {
            ans = ans * (rowIndex - i + 1);
            ans = ans / i;
            myAns.push_back(ans);
        }
        return myAns;
    }
};