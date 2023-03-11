var uniquePathsWithObstacles = function(grid) {
        let m=grid.length, n=grid[0].length;
        const dp = [...Array(m+1)].map((e) => Array(n+1).fill(0));
        dp[0][1]=1;
        for(let i=1;i<m+1;i++){
            for(let j=1;j<n+1;j++){
                dp[i][j]=grid[i-1][j-1]==1 ? 0:dp[i][j-1]+dp[i-1][j]; 
            }
        }
        return dp[m][n];
};