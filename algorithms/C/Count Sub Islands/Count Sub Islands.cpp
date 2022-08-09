class Solution {
public:
    bool res;
    void mark_current_island(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y,int r,int c){
        if(x<0 || x>=r || y<0 || y>=c || grid2[x][y]!=1)  //Boundary case for matrix
            return ;
        
        //if there is water on  grid1 for the location on B then our current island can't be counted and so we mark res as false 
        if(grid1[x][y]==0){
            res=false;
            return;
        }
        //Mark current cell as visited
        grid2[x][y] = 0;
        
        //Make recursive call in all 4 adjacent directions
        mark_current_island(grid1,grid2,x+1,y,r,c);  //DOWN
        mark_current_island(grid1,grid2,x,y+1,r,c);  //RIGHT
        mark_current_island(grid1,grid2,x-1,y,r,c);  //TOP
        mark_current_island(grid1,grid2,x,y-1,r,c);  //LEFT
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //For FAST I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid1.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols = grid1[0].size();
		
        //Iterate for all cells of the array
        int no_of_islands = 0;
		
        //dfs on grid2 
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid2[i][j]==1){
                    res=true;
                    mark_current_island(grid1,grid2,i,j,rows,cols);
                    //if current island of grid2 meets the requirement update the no of islands
                    if(res)
                        no_of_islands += 1;
                }
            }
        }
		
        return no_of_islands;
    }
};
