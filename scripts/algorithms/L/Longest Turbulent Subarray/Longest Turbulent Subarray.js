// Runtime: 154 ms (Top 12.50%) | Memory: 63.1 MB (Top 7.81%)
var maxTurbulenceSize = function(arr) {
    const len = arr.length;
    const dp = Array.from({ length: len + 1 }, () => {
        return new Array(2).fill(0);
    });
    let ans = 0;
    for(let i = 1; i < len; i++) {
        if(arr[i-1] > arr[i]) {
            dp[i][0] = dp[i-1][1] + 1;
        } else if(arr[i-1] < arr[i]) {
            dp[i][1] = dp[i-1][0] + 1;
        }
        ans = Math.max(ans, ...dp[i]);
    }

    // console.log(dp);
    return ans + 1;
};