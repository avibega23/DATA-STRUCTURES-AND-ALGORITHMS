class Solution {
    public:
        vector<int>nse(vector<int>&heights)
        {
            stack<int>st;
            vector<int>ans(heights.size());
            for(int i = heights.size()-1;i>=0;i--)
            {
                while(!st.empty()&&heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                ans[i] = st.empty()?heights.size():st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int>pse(vector<int>&heights)
        {
            stack<int>st;
            vector<int>ans(heights.size());
            for(int i = 0;i<heights.size();i++)
            {
                while(!st.empty()&&heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                ans[i] = st.empty()?-1:st.top();
                st.push(i);
            }
            return ans;
        }
        int largestRectangleArea(vector<int>& heights) {
            vector<int>NSE = nse(heights);
            vector<int>PSE = pse(heights);
            int maxi = 0;
            for(int i = 0;i<heights.size();i++)
            {
                int length = NSE[i] - PSE[i] - 1;
                maxi = max(maxi,length*heights[i]);
            }
            return maxi;
        }
    };