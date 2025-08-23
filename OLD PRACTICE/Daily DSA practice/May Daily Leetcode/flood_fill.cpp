class Solution {
public:
    void recurse(vector<vector<int>>&image,int sr,int sc,int color,int orginalColor)
    {
        if(image[sr][sc]==color) return;
        if(image[sr][sc]==orginalColor)
        {
            image[sr][sc] = color;
            int rowSide[4] = {-1,1,0,0};
            int colSide[4] = {0,0,-1,1};
            for(int i = 0;i<4;i++)
            {
                int nrow = sr+rowSide[i];
                int ncol = sc+colSide[i];

                if(nrow >=0 && nrow<image.size() && ncol >= 0 && ncol < image[0].size())
                {
                    recurse(image,nrow,ncol,color,orginalColor);
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orginalColor = image[sr][sc];
        recurse(image,sr,sc,color,orginalColor);
        return image;
    }
};