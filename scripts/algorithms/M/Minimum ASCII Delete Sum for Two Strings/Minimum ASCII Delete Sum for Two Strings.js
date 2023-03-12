var minimumDeleteSum = function(s1, s2) {
    const len1 = s1.length, len2 = s2.length;
    const dp = [...Array(len1+1)].map(() => Array(len2+1).fill(0));
    
    for(let i = 1; i <= len1; i++) {
        dp[i][0] = dp[i-1][0] + s1.charCodeAt(i-1);
    }
    
    for(let j = 1; j <= len2; j++) {
        dp[0][j] = dp[0][j-1] + s2.charCodeAt(j-1);
    }
    
    for(let i = 1; i <= len1; i++) {
        for(let j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                const del1 = s1.charCodeAt(i-1) + dp[i-1][j];
                const del2 = s2.charCodeAt(j-1) + dp[i][j-1];
                dp[i][j] = Math.min(del1, del2);
            }
        }
    }
    return dp[len1][len2];
};