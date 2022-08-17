class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vi>
    
    vvi forests;
    vvi moves;
    int R;
    int C;
    
    
    bool isValid(int x,int y){
        return x>=0&&x<R&&y>=0&&y<C;
    }
    
    int getShortestDistance(int sx,int sy,int ex,int ey){
        
        vvi vis = vvi(R,vi(C,0));
        queue<pair<int,int>>Q;
        Q.push({sx,sy});
        
        vis[sx][sy] = 1;
                
        
        int level = 0;
        
        while(!Q.empty()){
            
            queue<pair<int,int>>childQ;
            
            while(!Q.empty()){
                
                auto x = Q.front().first;
                auto y = Q.front().second;
                
                Q.pop();
                
                if(x==ex&&y==ey)
                    return level;
                
                for(auto ele:moves){
                    
                    int nextX = x+ele[0];
                    int nextY = y+ele[1];
                    
                    if(isValid(nextX,nextY)&&!vis[nextX][nextY]&&forests[nextX][nextY]>0){
                        childQ.push({nextX,nextY});
                        vis[nextX][nextY]=1;
                    }
                    
                }
                
                
            }
            Q=childQ;
               
            level++;
        }
        
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        
        moves={
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        
        forests = forest;
        
        R = forest.size();
        C = forest[0].size();
        
        if(forest[0][0]==0)
            return -1;
        
        vector<vector<int>>trees;
        int i=0;
        
        while(i<R){
            int j=0;
            while(j<C){
                if(forest[i][j]>1)
                    trees.push_back({forest[i][j],i,j});
                
                j++;
            }
            i++;
        }
        
        if(trees.empty())
            return -1;
        
        sort(trees.begin(),trees.end());
        
        int sx = 0;
        int sy = 0;
        
        int ans = 0;
        
        for(auto it:trees){
            
            int dis = getShortestDistance(sx,sy,it[1],it[2]);
            
            if(dis==-1)
                return -1;
            ans+=dis;
            sx = it[1];
            sy = it[2];
        }
        
        return ans;
        
    }
};
