vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    int ans = a[n-1];
    vector<int>maxAns;
    maxAns.push_back(ans);

    for(int i = n-1;i>=0;i--)
    {
      if (a[i] > ans) {
        ans = a[i];
        maxAns.push_back(ans);
      }
    }
    return maxAns;
}