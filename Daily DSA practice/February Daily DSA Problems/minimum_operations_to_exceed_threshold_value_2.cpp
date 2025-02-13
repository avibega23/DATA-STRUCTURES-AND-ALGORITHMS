int minOperations(vector<int> &arr, int k)
{
    int cnt = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());

    while (pq.size() >= 2 && pq.top() < k)
    {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();

        pq.push(x * 2 + y);
        cnt++;
    }

    return (pq.top() >= k) ? cnt : -1;
}