// Runtime: 397 ms (Top 81.82%) | Memory: 68.1 MB (Top 93.94%)

// Same as https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Time -> O(nlogn), where n = length of rides array
// Space -> O(n), where n = length of rides array

/**
 * @param {number} n
 * @param {number[][]} rides
 * @return {number}
 */
var maxTaxiEarnings = function(n, rides) {

    const len = rides.length

    rides.sort((a,b) => {
        return a[1] - b[1]
    })

    // Binary search
    function binarySearch(idx) {
        let low = 0, high = idx

        while(low < high) {
            let mid = Math.trunc((low+high)/2)

            if(rides[mid][1] <= rides[idx][0]) low = mid+1
            else high = mid
        }

        return high === 0 ? -1 : high-1
    }

    let dp = new Array(len).fill(0)
    dp[0] = rides[0][2] + (rides[0][1] - rides[0][0])

    for(let i=1; i<len; i++) {
        dp[i] = rides[i][2] + (rides[i][1] - rides[i][0])
        let j = binarySearch(i)

        if(j !== -1)
            dp[i] += dp[j]

        dp[i] = Math.max(dp[i], dp[i-1])
    }

    return dp[len-1]
};