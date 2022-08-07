////**  hindi me samjho ab// 
// agar mje left or right or bottom or top me 1 mila to me aaga badunga agar nahi
//mila mtlb ya to wo boundary  hai  uske baad 0  ara hai agar esa hai to cnt+=1 
//kardo kuki wo hi to meri boundary banegi . note : agar boundary hai mtlb 
//i <0 or j<0 or i>=n or j>=m to cnt+=1 kardo or agar box ke side walo me 0 hai to wahan bhi cnt+=1 . 
// hope it make sense 
// please upvote if you like my post 
class Solution {
public:
     int cnt =0 ;
bool vis[101][101] ;
    bool valid( int i , int j, int n , int m){
        if(i>=n or j>=m or i<0 or j<0 )
             return false;
        return true ;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(vis,false , sizeof(vis)) ;
        for(int i = 0 ; i <grid.size() ; i ++){ 
              for(int  j=0 ; j<grid[0].size() ; j++) {
                   
                  
                   if(grid[i][j]==1){
                       
                     solve(grid, i,j) ;
                       return cnt ;
                   }
              }        
         }
        return 69;
    }
 void  solve(vector<vector<int>>&grid, int i , int j ){
       int n = grid.size() ; 
     int m = grid[0].size() ;
 vis[i][j]=true ;
     if(!valid(i-1,j,n,m) or (valid(i-1,j,n,m) and grid[i-1][j]==0)){
         cnt++ ;
     }
     else if(valid(i-1,j,n,m)and !vis[i-1][j])
         solve(grid, i-1,j) ;
     
     if(!valid(i+1,j,n,m) or (valid(i+1,j,n,m) and grid[i+1][j]==0)){
         cnt++ ;
     }
        else if(valid(i+1,j,n,m)and !vis[i+1][j])
         solve(grid,i+1,j) ;
     
     if(!valid(i,j-1,n,m) or (valid(i,j-1,n,m) and grid[i][j-1]==0)){
         cnt++ ;
     }
          else if(valid(i,j-1,n,m)and !vis[i][j-1])
         solve(grid,i,j-1) ;
     
     if(!valid(i,j+1,n,m) or (valid(i,j+1,n,m) and grid[i][j+1]==0)){
         cnt++ ;
     }
          else if(valid(i,j+1,n,m)and !vis[i][j+1])
         solve(grid,i,j+1) ;
     
     
     
}
};
