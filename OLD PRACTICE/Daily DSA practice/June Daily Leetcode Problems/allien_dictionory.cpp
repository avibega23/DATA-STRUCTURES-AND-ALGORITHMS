class Solution {
  public:
    vector<int>topo(vector<vector<int>>&adj,int V,vector<int>&alphabet)
    {
        vector<int>indegree(V,0);
        for(int i = 0;i<adj.size();i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i = 0;i<V;i++)
        {
            if(alphabet[i] && indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(auto it:adj[top])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
    string findOrder(vector<string> &words) {
        // code here
        vector<int>alphabet(26,0);
        for(int i = 0;i<words.size();i++)
        {
            for(int j = 0;j<words[i].size();j++)
            {
                alphabet[words[i][j]-'a'] = 1;
            }
        }
        int V = 0;
        for(int i = 0;i<26;i++)
        {
            if(alphabet[i]==1) V++;
        }
        
        vector<vector<int>>adj(26);
        for(int i = 0;i<words.size()-1;i++)
        {   
            int flag = 0;
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            for(int j = 0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    flag = 1;
                    break;
                }
            }
            if(!flag && s1.size()>s2.size()) return "";
        }
        vector<int> topoArray = topo(adj,26,alphabet);
        string ans = "";
        if(topoArray.size()<V) return ans;
        for(int i = 0;i<topoArray.size();i++)
        {
            ans.push_back(topoArray[i]+'a');
        }
        return ans;
    }
};