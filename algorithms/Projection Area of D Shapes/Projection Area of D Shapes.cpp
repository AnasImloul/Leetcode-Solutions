class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res=0;
        // X-Y ( top )
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]) // if some cubes are present it is seen as of area 1 from top
                    res++; 
            }
        }
        
        // Z-X ( front )
        for(int i=0;i<grid.size();i++)
        {
            int m=grid[i][0];
            for(int j=1;j<grid[0].size();j++)
            {
                m=max(m,grid[i][j]);// from front, the tower with heightest height can only be seen in column
            }
            res+=m;
        }
        
        // Z-Y ( side )
        for(int j=0;j<grid[0].size();j++)
        {
            int m=grid[0][j];
            for(int i=1;i<grid.size();i++)
            {
                m=max(m,grid[i][j]);// // from side, the tower with heightest height can only be seen in row
            }
            res+=m;
        }
        return res;
    }
};
