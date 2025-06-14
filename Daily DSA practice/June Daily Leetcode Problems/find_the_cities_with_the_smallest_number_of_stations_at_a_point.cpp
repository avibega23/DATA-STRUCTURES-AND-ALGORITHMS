class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<matrix.size();i++)
        {
            matrix[i][i] = 0;
        }

        for(int i = 0;i<edges.size();i++)
        {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<matrix.size();i++)
            {
                for(int j = 0;j<matrix[i].size();j++)
                {
                    if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int minVal = INT_MAX;
        int minCity = -1;
        for(int i =0;i<n;i++)
        {
            int cnt = 0;
            for(int j = 0;j<n;j++)
            {
                if(i!=j && matrix[i][j]<=distanceThreshold)
                {
                    cnt++;
                }
            }
            if(cnt <= minVal)
            {
                minVal = cnt;
                minCity = i;
            }
        }
        return minCity;
    }
};