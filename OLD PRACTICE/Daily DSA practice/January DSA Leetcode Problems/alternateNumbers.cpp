vector<int> alternateNumbers(vector<int> &a)
{
    // Write your code here.
    int posIndex = 0;
    int negIndex = 1;
    vector<int> ans(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            ans[negIndex] = a[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = a[i];
            posIndex += 2;
        }
    }
    return ans;
}