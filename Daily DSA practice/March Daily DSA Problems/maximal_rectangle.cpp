class Solution {
    public:
        vector<int>PSE(vector<int>&arr)
        {
            stack<int>st;
            vector<int>ans(arr.size());
            for(int i = 0;i<arr.size();i++)
            {
                while(!st.empty()&&arr[st.top()]>=arr[i])
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
        int calcHisto(vector<int>&arr)
        {
            vector<int>pse = PSE(arr);
            vector<int>nse = NSE(arr);
            int maxi = 0;
            for(int i = 0;i<arr.size();i++)
            {
                int length = nse[i] - pse[i] - 1;
                maxi = max(maxi,length*arr[i]);
            }
            return maxi;
        }
        int maximalRectangle(vector<vector<char>>& matrix) {
            vector<int>ans(matrix[0].size(),0);
            int area = 0;
            for(int i = 0;i<matrix.size();i++)
            {
                for(int j = 0;j<matrix[0].size();j++)
                {
                    if((matrix[i][j]-'0')==1)
                    {
                        ans[j] += 1;
                    }
                    else
                    {
                        ans[j] = 0;
                    }
                }
                area = max(calcHisto(ans),area);
            }
            return area;
        }
    };