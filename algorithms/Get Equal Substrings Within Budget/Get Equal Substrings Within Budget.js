var equalSubstring = function(s, t, maxCost) {
    let dp = [], ans = 0;

    for (let i = 0, j = 0, k = 0; i < s.length; i++) {
        // overlay
        k += dp[i] = abs(s[i], t[i]);
        
        // non first
        if (k > maxCost) {
            k -= dp[j], j++;
            continue;
        }
        
        // eligible
        ans++;
    }

    return ans;

    // get abs value
    function abs(a, b) {
        return Math.abs(a.charCodeAt(0) - b.charCodeAt(0));
    }
};
