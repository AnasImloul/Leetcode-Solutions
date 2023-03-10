static int fast_io = []() 
{ 
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    return 0; 
}();

#ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif

class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        //initializing the dp form memoization
        dp.resize(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(205,-1)));

        //row and col for traversing the grid
        int row = 0;
        int col = 0;
        
        //mainitng a variable to keep the track of the open and the close bracket
        int k = 0;

        //fun function will return if there exist any path from top to bottom with valid vps
        return fun(grid,row,col,k);    
    }
    int fun(vector<vector<char>>&grid,int row,int col,int k)
    {
          if(row<0 or row>=grid.size() or col<0 or col>=grid[0].size())
          {
              return false;
          }

          if(grid[row][col] == '(')
          {
              k++;
          }      
          else if(grid[row][col] == ')')
          {
              k--;
          }

          if(k < 0) //no of cloing brackets are now more than no of opening brackets return flase
          return false;

          if(row == grid.size()-1 and col == grid[0].size()-1)   //if we reach the destination
          {
                if(k > 0)  //this means no of opening are more than closing 
                return false;

                if(k == 0)  //this means all the brackets are balances
                return true;

                if(k < 0)   //no of closing brackets are more than no of opening brackets
                return false;
          }
          
          //if the state is currently computed
          if(dp[row][col][k]!=-1)
          return dp[row][col][k];
     
          //checking all the possibility 
          int choise1 = fun(grid,row+1,col,k);
          int choise2 = fun(grid,row,col+1,k);

          return dp[row][col][k] = choise1 or choise2;
    }
};