// Runtime: 23 ms (Top 77.91%) | Memory: 23.3 MB (Top 61.26%)
class Solution {
public:
    int cal(vector<vector<int>>& grid,int i,int j,int& m,int& n){
        if(i==m || j==n || i<0 || j<0 || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return 1+cal(grid,i,j+1,m,n)+cal(grid,i+1,j,m,n)+cal(grid,i,j-1,m,n)+cal(grid,i-1,j,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=0;
                    area=cal(grid,i,j,m,n);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};