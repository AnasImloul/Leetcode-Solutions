class Solution {
public:
    
    int sum(vector<vector<int>> mat){
        int score = 0;
        
        
        
        for(int i=0;i<mat.size();i++){
            int p = mat[0].size()-1;
            for(int j=0;j<mat[0].size();j++){
                score+= mat[i][j]*pow(2,p);
                p--;
            }
        }
        
        return score;
    }
    
    int matrixScore(vector<vector<int>>& grid) {
//         if(grid.size()==1){
//             return ;
//         }
        
        
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
               for(int j=0;j<grid[0].size();j++){
                   if(grid[i][j]==0){
                       grid[i][j]=1;
                   }
                   else{
                        grid[i][j]=0;
                   }
               }
            }
        }
        
        
        
        
        vector<int> ind;
        
        for(int i=1;i<grid[0].size();i++){
            int ct=0;
            for(int j=0;j<grid.size();j++){
                ct+=grid[j][i];
               
            }
            if(ct<=grid.size()/2){
                ind.push_back(i);
            }
        }
        for(auto v:ind){
            cout<<v<<" ";
        }
        
        for(auto c:ind){
            for(int j=0;j<grid.size();j++){
                if(grid[j][c]==0){
                       grid[j][c]=1;
                   }
                   else{
                        grid[j][c]=0;
                   }
            }
        }
       
        
        
        
        
        return sum(grid);
        
        
        
        
        
        
       
    }