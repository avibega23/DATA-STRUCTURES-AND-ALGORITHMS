vector<int> printRow(int N)
{
    long long ans = 1;
    vector<int> myAns;
    myAns.push_back(ans);
    for (int i = 1; i < N + 1; i++)
    {
        ans = ans * (N - i + 1);
        ans = ans / i;
        myAns.push_back(ans);
    }
    return myAns;
}
vector<vector<int>> pascalTriangle(int N)
{
    // Write your code here.
    vector<vector<int>> ans;
    for (int i = 0; i < N; i++)
    {
        ans.push_back(printRow(i));
    }
    return ans;
}