
class Solution {
    public:
        vector<int>PSE(vector<int>&arr)
        {
            stack<int>st;
            vector<int>ans(arr.size());
            for(int i = 0;i<arr.size();i++)
            {
                while(!st.empty()&&arr[st.top()]>arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty()?-1:st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int>NSE(vector<int>&arr)
        {
            stack<int>st;
            vector<int>ans(arr.size());
            for(int i = arr.size()-1;i>=0;i--)
            {
                while(!st.empty()&&arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty()?arr.size():st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int>NGE(vector<int>&arr)
        {
            stack<int>st;
            vector<int>ans(arr.size());
            for(int i = arr.size()-1;i>=0;i--)
            {
                while(!st.empty()&&arr[st.top()]<=arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty()?arr.size():st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int>PGE(vector<int>&arr)
        {
            stack<int>st;
            vector<int>ans(arr.size());
            for(int i = 0;i<arr.size();i++)
            {
                while(!st.empty()&&arr[st.top()]<arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty()?-1:st.top();
                st.push(i);
            }
            return ans;
        }
        long long subArrayRanges(vector<int>& arr) {
            vector<int>nse = NSE(arr);
            vector<int>pse = PSE(arr);
            vector<int>nge = NGE(arr);
            vector<int>pge = PGE(arr);
            int mod = 1e9+7;
            long long mini = 0;
            long long maxi = 0;
            for(int i =0;i<arr.size();i++)
            {
                int leftS = i - pse[i];
                int rightS = nse[i] - i;
                int leftG = i - pge[i];
                int rightG = nge[i] - i;
    
                // maxi = (maxi + (((1LL*leftG*rightG)%mod)*arr[i]))%mod;
                // mini = (mini + (((1LL*leftS*rightS)%mod)*arr[i]))%mod;
                maxi += 1LL*leftG*rightG*arr[i]*1LL;
                mini += 1LL*leftS*rightS*arr[i]*1LL;
            }
            return maxi-mini;
        }
    };