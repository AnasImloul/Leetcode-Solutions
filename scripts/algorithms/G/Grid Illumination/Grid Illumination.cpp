// Runtime: 550 ms (Top 98.51%) | Memory: 116.6 MB (Top 61.19%)
class Solution {
public:

    // store info about rows , coulms and diagonal that is illuminated
    // if (i,j) is lamp , then every cell (x,y) is illuminated if
    // x==i (row) || y==j (column) || x+y == i+j (anti diagonal) || x-y == i-j (main diagonal)
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        vector<int>ans;
        unordered_map<int,int>row,col,mainDiag,antiDiag;
        set<pair<int,int>>s;

        for(auto &l : lamps){
            int x = l[0],y=l[1];
            // Even if the same lamp is listed more than once, it is turned on.
            // To prevent duplicate entries
            if(s.find({x,y}) == s.end())
            {
                row[x]++;
                col[y]++;
                antiDiag[x+y]++;
                mainDiag[x-y]++;
                s.insert({x,y}); // This helps us to get the lamp in O(1)
            }
        }

        for(auto &q : queries)
        {
            // For every query {x,y} do 2 things :
            // 1. Check whether grid[x][y] is illuminated or not, accordingly set answer either to '1' OR '0'
            // 2. if grid is illuminated, turn off the lamps at {x,y} and 8 adjacent lamps = 9 lamps

            int x = q[0],y = q[1];
            if(row[x]>0 or col[y]>0 or antiDiag[x+y]>0 or mainDiag[x-y]>0)
            {
                // illumination
                ans.push_back(1);

                // Turn off the 9 lamps = 1 center and 8 adjacent lamps
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){

                        int nx = x+i;
                        int ny = y+j;
                        // NxN board, check boundaries condition
                        if(nx >= 0 and nx < n and ny >=0 and ny < n and s.find({nx,ny})!=s.end())
                        {
                            row[nx]--;
                            col[ny]--;
                            antiDiag[nx+ny]--;
                            mainDiag[nx-ny]--;
                            s.erase({nx,ny});
                        }
                    }
                }
            }
            else // No illumination
                ans.push_back(0);
        }
        return ans;
    }
};