// Runtime: 217 ms (Top 82.22%) | Memory: 125.90 MB (Top 26.67%)

/**
 * @param {number[][]} events
 * @param {number} k
 * @return {number}
 */

var f = function(ind,k,events,dp){
    if(ind == events.length || k == 0) return 0;
    
    if(dp[ind][k] != -1) return dp[ind][k];
    let take = events[ind][2];
    for(let i = ind+1; i < events.length; ++i){
        if(events[ind][1] < events[i][0]){
            take += f(i,k-1,events,dp);
            break;
        }
    }
    let notTake = f(ind+1,k,events,dp);
    return dp[ind][k] = Math.max(take,notTake);
}
var maxValue = function(events, k) {
    const dp = [];
    events.sort((a,b)=>a[0]===b[0]?a[1]-b[1]:a[0]-b[0])
    for(let i = 0; i < events.length; ++i){
        dp[i] = new Array(k+1).fill(-1);
    }
    return f(0,k,events,dp);
};
