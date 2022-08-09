class Solution {
public:
    bool isValid(int r1, int r2, int c1, int c2, vector<vector<int>>& grid, vector<vector<int>>& rg, vector<vector<int>>& cg,int checkSum){
        //Checking all row sums between top and bottom row
        for(int i = r1 + 1; i<r2; i++){
            int sum = rg[i][c2];
            if(c1>0)sum-=rg[i][c1-1];
            if(sum!=checkSum)return false;
        }
        //Checking all columns between left and right column 
        for(int j = c1 + 1; j<c2; j++){
            int sum = cg[r2][j];
            if(r1>0)sum-=cg[r1-1][j];
            if(sum!=checkSum)return false;
        }
        int sum = 0;
        //right diagonal
        for(int i = r1, j = c1; i<=r2&&j<=c2; i++, j++){
            sum+=grid[i][j];
        }
        if(sum!=checkSum)return false;
        sum = 0;
        //left diagonal
        for(int i = r1, j = c2; i<=r2&&j>=c1; i++, j--){
            sum+=grid[i][j];
        }
        if(sum!=checkSum)return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>rg, cg;
        rg = grid;
        cg = grid;
        //Generating row prefix sum matrix
        for(int i = 0; i<m; i++){
            for(int j = 1; j<n; j++){
                rg[i][j] += rg[i][j-1];
            }
        }
        //Generating column prefix sum matrix
        for(int j = 0; j<n; j++){
            for(int i = 1; i<m; i++){
                cg[i][j] += cg[i-1][j];
            }
        }
        int ans = 1;
        //For each cell in the loop, we find the larget magic square with cell {i,j} at the top left corner.
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(m-i<=ans)return ans;//The largest square with it's top row as i will have at max a dimension = m-i, and in case are answer is already >= this dimension, we can simply return our answer
                //Pruning step -->
                //We only need to consider squares whose sizes our greater than our current answer, so we prune our search by starting from squares having side-lengths greater than ans.
                int r = i + ans;
                int c = j + ans;
                while(r<m&&c<n){
                    //For a square having it's 4 corners defined by {i,j,r,c}, we calculate the sum of all these 4 sides, and call our isValid function in case these sums are equal
                    int rsum1 = j>0 ? rg[i][c] - rg[i][j-1] : rg[i][c];//top row sum
                    int csum1 = i>0 ? cg[r][j] - cg[i-1][j] : cg[r][j];//left column sum
                    int rsum2 = j>0 ? rg[r][c] - rg[r][j-1] : rg[r][c];//bottom row sum
                    int csum2 = i>0 ? cg[r][c] - cg[i-1][c] : cg[r][c];//right column sum
                    if(rsum1==csum2&&rsum2==csum2&&isValid(i,r,j,c,grid, rg, cg, rsum1)){
                        ans = max(ans, r-i+1);
                    }
                    r++;
                    c++;
                }
            }
        }
        return ans;
    }
};
