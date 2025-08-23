class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        while(pq.size()>1)
        {
            int top = pq.top();pq.pop();
            int second = pq.top();pq.pop();
            sum += top+second;
            pq.push(top+second);

        }
        return sum;
    }
};