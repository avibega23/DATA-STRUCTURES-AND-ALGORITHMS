//https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int largestHisto(vector<int>&nums)
    {
        int n = nums.size();
        stack<int>st;
        int maxi = 0;

        for(int i = 0;i<=n;i++)
        {
            while(!st.empty() && (i ==n || nums[st.top()]>=nums[i]))
            {
                int height = nums[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top()-1;

                maxi = max(maxi,height*width);

            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = 0;
        vector<int>height(m,0);

        for(int i = 0 ; i < n;i++)
        {
            for(int j = 0 ; j<m ;j++)
            {
                if(matrix[i][j]=='1')height[j]++;
                else height[j] = 0;
            }
            int area = largestHisto(height);
            maxi = max(maxi,area);
        }
        return maxi;
    }
};