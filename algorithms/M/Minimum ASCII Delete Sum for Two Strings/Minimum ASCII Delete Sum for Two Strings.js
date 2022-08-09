var minimumDeleteSum = function(s1, s2) {
    s1 = s1.split('');
    s2 = s2.split('');
    
    const s1Len = s1.length, s2Len = s2.length;
    const dp = new Array(s1Len).fill(-1).map(() => {
        return new Array(s2Len).fill(-1);
    });
    const solve = (i = 0, j = 0) => {
        let cost = 0;
        if(i == s1Len) {
            while(j < s2Len) cost += s2[j++].charCodeAt(0);
            return cost;
        }
        
        if(j == s2Len) {
            while(i < s1Len) cost += s1[i++].charCodeAt(0);
            return cost;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return solve(i + 1, j + 1);
        
        let del = solve(i + 1, j) + s1[i].charCodeAt(0);
        let add = solve(i, j + 1) + s2[j].charCodeAt(0);
        
        return dp[i][j] = Math.min(add, del);
    }
    
    return solve();
};
