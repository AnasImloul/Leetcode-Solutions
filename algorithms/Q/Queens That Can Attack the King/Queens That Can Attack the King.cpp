class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) 
    {
        vector<vector<int>> ans;
        vector<vector<int>> board(8, vector<int>(8, 0));

        for(auto queen: queens) board[queen[0]][queen[1]] = 1;
        
        for(int x=-1; x<=1; x++)  // Both loops are for checking in all the 8 possible directions
        {
            for(int y=-1; y<=1; y++)
            {
                if(x == 0 and y == 0) continue;
                int startx = king[0], starty = king[1];
                
                while(startx >= 0 and startx < 8 and starty >= 0 and starty < 8)
                {
                    if(board[startx][starty] == 1)  // If queen is found, append it to ans and break
                    {
                        ans.push_back({startx, starty});
                        break;
                    }
                    startx += x, starty += y;      // Otherwise keep moving forward in earlier direction
                }
            }
        }
        return ans;
    }
};


