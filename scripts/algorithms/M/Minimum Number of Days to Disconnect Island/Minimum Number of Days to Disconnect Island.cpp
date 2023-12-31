// Runtime: 8 ms (Top 93.23%) | Memory: 10.30 MB (Top 84.9%)

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        //if the graph has already greater than 1 components than ans is 0
        //if the graph has any articulation point than ans is 1
        //else ans is 2
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        //discovery time
        vector<vector<int>> disc(n,vector<int>(m,0));
        //low time
        vector<vector<int>> low(n,vector<int>(m,0));
        //visited array
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        //direction array
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        //if ok is true means there is a articulation point in the graph
        bool ok = false;
        //dfs call
        function<void(int,int,int&,int)> dfs = [&](int x,int y,int &time,int p){
            //mark the nodes as visited and update their low and disc time
            visited[x][y] = true;
            disc[x][y] = low[x][y] = time++;
            //for root if there are more than 1 recursive tree than root is a articulation point
            int rootCall = 0;
            //going in all direction and making a dfs call
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                //if child cordinates are valid and there is a 1 at that point ans also it is not parent
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && newX*m+newY != p){
                    if(!visited[newX][newY]){
                        dfs(newX,newY,time,x*m+y);
                        //update the low time
                        low[x][y] = min(low[x][y],low[newX][newY]);
                        //checking whether [x,y] is articulation point or not
                        if(p == -1){
                            rootCall++;
                        }else if(disc[x][y] <= low[newX][newY]){
                            ok = true;
                        }
                    }else{
                        //updating the low time
                        low[x][y] = min(low[x][y],disc[newX][newY]);
                    }
                }
            }
            //if root and more than 1 recurive tree formed than articulation point
            if(p == -1 && rootCall > 1){
                ok = true;
            }
        };
        //counting the number of 1's and making dfs call
        int to1 = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    to1++;
                    if(!visited[i][j]){
                        int time = 1;
                        dfs(i,j,time,-1);
                        count++;
                    }
                }
            }
        }
        
        if(count > 1){
            //if more than one components are formed
            return 0;
        }else if(ok){
            //if onlu one component is formed and there is a articulation point
            return 1;
        }else{
            //if total number of 1 is 1
            if(to1 == 1){
                return 1;
            }else if(to1 == 0){
                //if total number of 1 is 0
                return 0;
            }
            //else
            return 2;
        }
    }
};
