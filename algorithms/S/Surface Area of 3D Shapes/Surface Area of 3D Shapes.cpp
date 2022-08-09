class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        
        for(int i  = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
				//adding 4 sides
                area += grid[i][j]*4;
				
				//adding two because of there will only one top and one bottom if cube is placed upon each other
                if(grid[i][j] != 0)
                    area+=2;
				
				//subtracting adjacent side area if any
                if(i-1 >= 0)
                    area -= min(grid[i-1][j], grid[i][j]);
                if(i+1 < grid.size())
                    area -= min(grid[i+1][j], grid[i][j]);
                if(j-1 >= 0)
                    area -= min(grid[i][j-1], grid[i][j]);
                if(j+1 < grid.size())
                    area -= min(grid[i][j+1], grid[i][j]);
            }
        }
        
        return area;
    }
};
