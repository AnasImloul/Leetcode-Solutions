// Runtime: 121 ms (Top 56.75%) | Memory: 44.9 MB (Top 48.84%)
var maxProfit = function(k, prices) {
    const len = prices.length;
    let dp = new Array(len).fill(0);
    dp = dp.map(() => new Array(2).fill(0).map(() => new Array(k+1).fill(-1)));
    const solve = (day = 0, cap = k, buy = 0) => {
        if(day == len || cap == 0) return 0;

        if(dp[day][buy][cap] != -1) return dp[day][buy][cap];

        let take, notake;
        notake = solve(day + 1, cap, buy);
        if(buy == 0) {
            take = solve(day + 1, cap, 1) - prices[day];
        } else {
            take = solve(day + 1, cap - 1, 0) + prices[day];
        }
        return dp[day][buy][cap] = Math.max(take, notake)
    };
    return solve();
};