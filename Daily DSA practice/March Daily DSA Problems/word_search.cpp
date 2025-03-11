class Solution {
    public:
        int m;
        int n;
        bool helper(vector<vector<char>>&board,string word,int r,int c,int ind)
        {
            if(ind == word.size()) return true;
    
            if(r<0||c<0||r>=m||c>=n||board[r][c]!=word[ind]||board[r][c]=='$')
            {
                return false;
            }
    
            char temp = board[r][c];
            board[r][c] = '$';
    
            if(helper(board,word,r+1,c,ind+1)||
               helper(board,word,r-1,c,ind+1)||
               helper(board,word,r,c+1,ind+1)||
               helper(board,word,r,c-1,ind+1) 
                )
            return true;
    
            board[r][c] = temp;
            return false;
        }
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();
            n = board[0].size();
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(board[i][j]==word[0]&&helper(board,word,i,j,0))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };