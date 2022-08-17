int f[8][8][8][8][67];

class Solution {
public:
    
    int n,m,cj,mj;   //cj means catJump, mj means mouseJump
    vector<string> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
	//dp[cat_x][cat_y][mouse_x][mouse_y][steps], 0 = cat wins, 1 = mouse wins.
    int dp(int cx, int cy, int mx, int my, int k){ 
        if(k >= 67) return 0;    //when steps >= 67, cat wins
        int& v = f[cx][cy][mx][my][k];
        if(v != -1) return v;  
        
        if(k & 1){    //step for cat
            for(int i = 0; i < 4; i++){
                for(int j = 0; j <= cj; j++){
                    int x = cx + dx[i]*j, y = cy + dy[i]*j;
                    if(x < 0 or x >= n or y < 0 or y >= m or g[x][y] == '#') break;
					 //If Cat occupies the same position as Mouse, Cat wins.
                    if(x == mx and y == my) return v = 0;  
					//If Cat reaches the food first, Cat wins.
                    if(g[x][y] == 'F') return v = 0;
                    if(!dp(x,y,mx,my,k+1)) return v = 0;
                }
            }
            return v = 1;
        }
        else{  //step for mouse
            for(int i = 0; i < 4; i++){
                for(int j = 0; j <= mj; j++){
                    int x = mx + dx[i]*j, y = my + dy[i]*j;
                    if(x < 0 or x >= n or y < 0 or y >= m or g[x][y] == '#') break;
					//mouse will not reach cat's position
                    if(x == cx and y == cy) continue;
					//If Mouse reaches the food first, Mouse wins.
                    if(g[x][y] == 'F') return v = 1;
                    if(dp(cx,cy,x,y,k+1)) return v = 1;
                }
            }
            return v = 0;
        }
    }

    
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        g = grid;
        n = grid.size(), m = g[0].size(), cj = catJump, mj = mouseJump;
        //positions of cat and mouse
        int cx,cy,mx,my;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == 'C') cx = i, cy = j;
                else if(g[i][j] == 'M') mx = i, my = j;
        memset(f, -1, sizeof f);
        return dp(cx, cy, mx, my, 0);
    }
};
