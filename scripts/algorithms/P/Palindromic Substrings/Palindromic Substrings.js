// Runtime: 91 ms (Top 28.5%) | Memory: 71.62 MB (Top 8.5%)

var countSubstrings = function(s) {
    const n = s.length;
    const dp = [...Array(n)].map(() => Array(n).fill(false));
    let count = 0;
    
    // Base case: single letter substrings
    for(let i = 0; i < n; i++) {
        dp[i][i] = true;
        count++
    }
    
    // Base case: double letter substrings
    for(let i = 0; i < n-1; i++) {
        dp[i][i+1] = (s[i] === s[i+1]);
        dp[i][i+1] && count++;
    }
    
    // substrings longer than 2 chars
    for(let len = 3; len <= n; len++) {
        let start = 0, end = start+len-1;
        
        while(end < n) {
            dp[start][end] = (dp[start+1][end-1] && s[start] === s[end]);
            dp[start][end] && count++;
            start++; end++;
        }
    }
    return count;
};