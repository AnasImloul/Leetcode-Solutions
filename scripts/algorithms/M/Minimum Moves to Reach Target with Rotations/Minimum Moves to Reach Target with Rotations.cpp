// Runtime: 296 ms (Top 23.08%) | Memory: 45.5 MB (Top 20.19%)
class Solution {

public:

int n;
set<vector<int>> visited;
bool candown(vector<vector<int>>& grid,int x,int y,bool hor){
    if(!hor){
        if(x+2<n && grid[x+1][y]==0 && grid[x+2][y]==0 && !visited.count({x+1,y,hor})){
            return true;
        }
    }else{
        if(x+1<n && y+1<n && grid[x+1][y]==0 && grid[x+1][y+1]==0 && !visited.count({x+1,y,hor})){
            return true;
        }
    }

    return false;
}

bool canright(vector<vector<int>>& grid,int x,int y,bool hor){
    if(hor){
        if(y+2<n && grid[x][y+1]==0 && grid[x][y+2]==0 && !visited.count({x,y+1,hor})){
            return true;
        }
    }else{
        if(y+1<n && x+1<n && grid[x][y+1]==0 && grid[x+1][y+1]==0 && !visited.count({x,y+1,hor})){
            return true;
        }
    }

    return false;
}

bool canrot(vector<vector<int>>& grid,int x,int y,bool hor){
    if(hor){
        if(y+1<n && x+1<n && grid[x+1][y]==0 && grid[x+1][y+1]==0 && !visited.count({x,y,!hor})){
            return true;
        }
    }else{
        if(x+1<n && y+1<n && grid[x][y+1]==0 &&grid[x+1][y+1]==0 && !visited.count({x,y,!hor})){
            return true;
        }
    }
    return false;
}

int minimumMoves(vector<vector<int>>& grid) {
    queue<array<int, 3>> q;
    q.push({0,0,true});
    int ans=0;
    n=grid.size();
    while(!q.empty()){
        int size=q.size();
        while(size--){
            auto a=q.front();
            q.pop();
            if(visited.count({a[0],a[1],a[2]})){
                continue;
            }
            visited.insert({a[0],a[1],a[2]});
            int x=a[0];
            int y=a[1];
            if(x==n-1 && y==n-2 && a[2]==1){
                return ans;
            }
            if(candown(grid,x,y,a[2])){
                q.push({x+1,y,a[2]});
            }
            if(canrot(grid,x,y,a[2])){
                q.push({x,y,!a[2]});
            }
            if(canright(grid,x,y,a[2])){
                q.push({x,y+1,a[2]});
            }
        }
        ans++;
    }
    return -1;
}
};