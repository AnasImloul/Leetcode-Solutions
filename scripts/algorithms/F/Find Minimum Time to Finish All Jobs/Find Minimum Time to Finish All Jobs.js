// Runtime: 7724 ms (Top 6.25%) | Memory: 48.8 MB (Top 25.00%)
var minimumTimeRequired = function(jobs, k) {
    let n=jobs.length, maskSum=[...Array(1<<n)].map(d=>0)
    for(let mask=0;mask<(1<<n);mask++) //pre-store the sums of every mask
        for(let i=0;i<n;i++)
            maskSum[mask]+=Number(((1<<i) & mask)!=0)*jobs[i]
    let dp=[...Array(k+1)].map(d=>[...Array(1<<n)].map(d=>Infinity))
    dp[0][0]=0
    for(let i=1;i<=k;i++) //for each new person
        for(let curmask=0;curmask<(1<<n);curmask++) //guess what his mask can be, what items can he select
            for(let prevmask=0;prevmask<(1<<n);prevmask++) // but also, guess what the previous i-1 persons took already
                if((curmask&prevmask)===0) //obviously, 2 people can't take the same job
                    dp[i][curmask|prevmask]=Math.min(dp[i][curmask|prevmask],Math.max(dp[i-1][prevmask],maskSum[curmask]))
    return dp[k][(1<<n) -1]
};