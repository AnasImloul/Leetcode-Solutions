class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        queue<vector<int>> nextOrangesToRot;
        for(int r = 0; r < R; ++r)
            for(int c = 0; c < C; ++c)
                if(grid[r][c] == 2)
                    nextOrangesToRot.push({r, c});
        
        vector<int> xDir {-1, 0, 0, 1};
        vector<int> yDir {0, 1, -1, 0};
        int totalTime = 0;
        while(!nextOrangesToRot.empty())
        {
            int size = nextOrangesToRot.size();
            while(size--)
            {
                vector<int>& currOrangeCell =  nextOrangesToRot.front();
                
                for(int i = 0; i < 4; ++i)
                {
                    int nextR = currOrangeCell[0] + xDir[i];
                    int nextC = currOrangeCell[1] + yDir[i];
                    if(nextR >= 0 && nextR < R && 
                       nextC >= 0 && nextC < C && grid[nextR][nextC] == 1)
                    {
                        grid[nextR][nextC] = 2; //rotted
                        nextOrangesToRot.push({nextR, nextC});
                    }
                }
                nextOrangesToRot.pop();
            }
            if(nextOrangesToRot.size())
                totalTime++;
        }
        for(int r = 0; r < R; ++r)
            for(int c = 0; c < C; ++c)
                if(grid[r][c] == 1)
                   return -1;
        return totalTime;
    }
};
