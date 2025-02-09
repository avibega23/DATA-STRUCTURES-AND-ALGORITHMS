class Solution {
    public:
        vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
            unordered_map<int,vector<int>>mpp;
            int m = mat.size();
            int n = mat[0].size();
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    mpp[i-j].push_back(mat[i][j]);
                }
            }
            for(auto& [ch,vec]:mpp)
            {
                sort(vec.begin(),vec.end());
            }
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    mat[i][j] = mpp[i-j].front();
                    mpp[i-j].erase(mpp[i-j].begin());
                }
            }
        return mat;
        }
    };