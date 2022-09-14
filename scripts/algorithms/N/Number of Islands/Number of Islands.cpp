// Runtime: 83 ms (Top 18.08%) | Memory: 12.3 MB (Top 54.41%)
class Solution {
public:

    void calculate(vector<vector<char>>& grid, int i, int j)
    {
        if(i>=grid.size() || j>=grid[i].size() || i<0 || j<0)
            return;

        if(grid[i][j]=='0')
            return;

        grid[i][j] = '0';
        calculate(grid,i,j-1);
        calculate(grid,i-1,j);
        calculate(grid,i,j+1);
        calculate(grid,i+1,j);

    }

    int numIslands(vector<vector<char>>& grid) {

        int ans = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='0')
                    continue;

                else if (grid[i][j]=='1')
                {
                    ans++;
                    calculate(grid,i,j);
                }
            }
        }
        return ans;
    }
};