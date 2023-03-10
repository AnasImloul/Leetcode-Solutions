/**
 * @param {number[][]} events
 * @param {number} k
 * @return {number}
 */
var maxValue = function(events, k) {
    events = events.sort((a, b) => a[1] - b[1]);
    const n = events.length;
    var ans = 0;
    var dp = Array.from(Array(k+1), () => new Array(n).fill(0));
    
    for(let i = 0; i < n; i++) {
        dp[1][i] = Math.max((i ? dp[1][i-1] :0), events[i][2]);
        ans = Math.max(dp[1][i], ans);
    }
    
    function binarySearch(l, r, target) {
        var pos = -1;
        while(l <= r) {
            const mid = Math.floor((l+r)/2);
            if (events[mid][1] < target) {
                pos = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return pos;
    }
    
    for(let i = 0; i < n; i++) {
        const j = binarySearch(0, i-1, events[i][0]);
            for(let l = 2; l <= k; l++) {
                dp[l][i] = Math.max(( j >= 0 ? dp[l-1][j] + events[i][2] : 0), (i ? dp[l][i-1] : 0));
                ans = Math.max(dp[l][i], ans);
            }
    }
    
    return ans;
};