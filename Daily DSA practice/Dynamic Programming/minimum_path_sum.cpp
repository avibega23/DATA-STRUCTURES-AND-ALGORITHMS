//recursive solution TLE
class Solution {
public:
    int recurse(int i,int j,vector<vector<int>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i > m-1 || j > n-1) return 1e9;

        int down = grid[i][j] + recurse(i+1,j,grid);
        int right = grid[i][j] + recurse(i,j+1,grid);


        return min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return recurse(0,0,grid);
    }
};