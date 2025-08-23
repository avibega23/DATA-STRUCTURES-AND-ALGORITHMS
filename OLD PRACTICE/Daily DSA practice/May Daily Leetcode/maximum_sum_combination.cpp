class Solution {
  public:
    struct compare{
        bool operator()(pair<int,pair<int,int>>p1,pair<int,pair<int,int>>p2)
        {
            return p1.first < p2.first;
        }
    };
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        vector<int>ans;
        set<pair<int,int>>check;
        
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare>pq;
        
        pq.push({A[0]+B[0],{0,0}});
        check.insert({0,0});
        
        while(K-- && !pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back(sum);
            if(i+1 < N && check.find({i+1,j})==check.end())
            {
                pq.push({A[i+1]+B[j],{i+1,j}});
                check.insert({i+1,j});
            }
            if(j+1<N && check.find({i,j+1})== check.end())
            {
                pq.push({A[i]+B[j+1],{i,j+1}});
                check.insert({i,j+1});
            }
        }
        return ans;
    }
};