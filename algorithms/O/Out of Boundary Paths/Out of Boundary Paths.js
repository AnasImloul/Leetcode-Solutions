vector<vector<vector<int>>> dp;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int mod = 1e9+7;

int fun(int i,int j,int n,int m,int k){
    
    if(i < 0 || j < 0 || i == n || j == m)return 1;
    else if(k == 0)return 0;
    
    if(dp[i][j][k] != -1)return dp[i][j][k];
    
    int ans = 0;
    for(int c = 0; c < 4; c++){
        int ni = i+dx[c] , nj = j+dy[c];
        ans = (ans + fun(ni,nj,n,m,k-1)) % mod;
    }
    
    return dp[i][j][k] = ans;
}

int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
    
    dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
	
    return fun(startRow, startCol,m,n,maxMove);
}
