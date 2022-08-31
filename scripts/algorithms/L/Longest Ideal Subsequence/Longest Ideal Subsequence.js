// Runtime: 245 ms (Top 43.75%) | Memory: 45.1 MB (Top 66.96%)
var longestIdealString = function(s, k) {
    let n = s.length
    let dp = Array(26).fill(0);
    let ans = 0;
    for(let i=0; i<n; i++){
        const cur = s.charCodeAt(i)-97;
        dp[cur] += 1;
        for(let j=Math.max(0, cur-k); j<=Math.min(cur+k, 25); j++){
            if(j !== cur){
                dp[cur] = Math.max(dp[cur], dp[j]+1);
            }
        }
        ans = Math.max(dp[cur], ans)
    }
    return ans;
};