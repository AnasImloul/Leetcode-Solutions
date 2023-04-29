class Solution {
public:

    bool isSafe(int i,int j,int r,int c,vector<vector<char>> &arr,vector<vector<bool>> &visited){
           if(i<0 || i>r || j<0 || j>c){
             return false;
         }
       //  cout<<arr[i][j]<<" ";
        if(arr[i][j]!='X'){
            return false;
        }
        if(arr[i][j] == 'X' && visited[i][j] == true){
            return false;
        }

        if(arr[i][j] == 'X' && visited[i][j] == false){
            return true;
        }
         return false;
    
    }

    void solve(vector<vector<char>> &arr,vector<vector<bool>> &visited,int &r,int &c,int i,int j){

        if((i>r && j>c) && (i<0 && j<0)){
            return;
        }

        // down (i+1,j)
        if(isSafe(i+1,j,r,c,arr,visited)){
             visited[i+1][j] = true;
             solve(arr,visited,r,c,i+1,j);
        }else{
            // if(arr[i][j] == 'X'){
            //      visited[i][j] = true;
            // }
        }
        // // right (i,j+1)

        if(isSafe(i,j+1,r,c,arr,visited)){
             visited[i][j+1] = true;
             solve(arr,visited,r,c,i,j+1);
        }else{
            // if(arr[i][j] == 'X'){
            //      visited[i][j] = true;
            // }
        }
        // left (i,j-1);
        if(isSafe(i,j-1,r,c,arr,visited)){
            visited[i][j-1] = true;
             solve(arr,visited,r,c,i,j-1);
        }else{
            // if(arr[i][j] == 'X'){
            //      visited[i][j] = true;
            // }
        }
        // up   (i-1,j)
        if(isSafe(i-1,j,r,c,arr,visited)){
             visited[i-1][j] = true;
             solve(arr,visited,r,c,i-1,j);
        }else{
            // if(arr[i][j] == 'X'){
            //      visited[i][j] = true;
            // }
        }

    }
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size()-1;
        int col = board[0].size()-1;
        vector<vector<bool>> isVisited(row+1,vector<bool>(col+1,false));
        vector<vector<int>> toStart;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == 'X'){
                    vector<int> temp(2);
                    temp[0] = i;
                    temp[1] = j;
                  //  cout<<i<<" "<<j<<endl;
                    toStart.push_back(temp);
                }
            }
        }
        int ans = 0;
         for(int i=0;i<toStart.size();i++){
            if(isVisited[toStart[i][0]][toStart[i][1]]){

            }else{
            isVisited[toStart[i][0]][toStart[i][1]] = true;
             solve(board,isVisited,row,col,toStart[i][0],toStart[i][1]);
             ans++;
            }
             
         }

        //  for(auto cc:isVisited){
        //      for(auto c:cc){
        //          cout<<c<<" ";
        //      }
        //      cout<<endl;
        //  }

        return ans;
    }
};