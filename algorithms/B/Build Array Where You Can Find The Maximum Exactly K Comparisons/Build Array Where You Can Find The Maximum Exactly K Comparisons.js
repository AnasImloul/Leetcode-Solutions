var numOfArrays = function(n, m, k){ 
    let mod=1e9+7,
        // dp[i][c][j] the number of arrays of length i that cost c and their max element is j  
        dp=[...Array(n+1)].map(d=>[...Array(k+1)].map(d=>[...Array(m+1)].map(d=>0))),
        // prefix[i][k][j] holds the prefix sum of dp[i][k][:j] 
        prefix=[...Array(n+1)].map(d=>[...Array(k+1)].map(d=>[...Array(m+1)].map(d=>0)))
    //basecases
    dp[0][0][0] = 1
    prefix[0][0].fill(1)
    for(var i = 1; i <= n; i++) //length of array
        for(var x = 1; x <= k; x++) //curcost
            for(var j = 1; j <= m; j++) //curmax
                // the previous max can be anything <j with a cost of x-1, to which we append j 
                dp[i][x][j] += prefix[i-1][x-1][j-1],
                // we can also append any number <=j to an array of length i-1 that already costs x,
                //therefore not increasing the cost
                dp[i][x][j] += dp[i - 1][x][j] *j ,
                dp[i][x][j] %= mod,
                prefix[i][x][j]=(prefix[i][x][j-1]+dp[i][x][j])%mod
    return dp[n][k].reduce((a,c)=>(a+c)%mod)
};
