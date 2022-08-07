
var numSquares = function(n) {
    let dp = new Array(n+1).fill(Infinity);
    
    dp[0] = 0;
    
    for(let i=1; i <= n; i++){
        for(let k=1; k*k <= i; k++){
            dp[i] = Math.min(dp[i],dp[i - (k*k)] + 1);
        }
    }
    
    return dp[n];
};