/**
 * @param {number[]} rods
 * @return {number}
 */
var tallestBillboard = function(rods) {
    let len = rods.length;
    if (len <= 1) return 0;
    let dp = [];
    for (let i = 0; i < len + 5; i++) {
        dp[i] = [];
        for (let j = 0; j < 5005 * 2; j++) {
            dp[i][j] = -1
        }
    }
    return solve(0, 0, rods, dp);
}

var solve = function(i, sum, rods, dp) {
  if (i == rods.length) {
        if (sum == 0) {
            return 0
        }else{
            return -5000
        }
    }
    if (dp[i][sum + 5000] != -1) {
        return dp[i][sum + 5000];
    }
    let val = solve(i + 1, sum, rods, dp);
    val = Math.max(val, solve(i + 1, sum + rods[i], rods, dp) + rods[i]);
    val = Math.max(val, solve(i + 1, sum - rods[i], rods, dp));
    dp[i][sum + 5000] = val;
    return val;
}


