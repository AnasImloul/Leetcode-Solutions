// Runtime: 82 ms (Top 95.60%) | Memory: 50 MB (Top 44.03%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubarraySumCircular = function(nums) {
    let n = nums.length;

    // Kadane for single interval
    let curr = nums[0]; // dp[j] Maximum sum subbarray till j
    let ans = nums[0]; // Maximum of all dps till j i.e. max(dp[0], dp[1], ... dp[i], ...dp[j]);

    for(let i = 1; i < n; i++) {
        curr = nums[i] + Math.max(0, curr);
        ans = Math.max(ans, curr);
    }

    /**
    * If we don't find answer using kadane using above logic then that means only one thing
    * some answer is present in 1st half and second in other half (since it is circular array)
    **/

    let rightSum = new Array(n); // Sum from Right, used to represent 2nd half of the solution

    rightSum[n - 1] = nums[n - 1];

    for(let i = n - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + nums[i];
    }

    let maxRightSum = new Array(n); // Used to fast fetch max right sum till given point
    maxRightSum[n - 1] = rightSum[n - 1];

    for(let i = n - 2; i >= 0; i--) {
        maxRightSum[i] = Math.max(maxRightSum[i + 1], rightSum[i]);
    }

    /**
    * Now solution is max of:
    * [Sum of [A0 --- Ai] + Maximum [Ai+2 --- An]]
    * Considering i + 1 will be equivalent to kadane which we already discussed above.
    **/
    let leftSum = 0;
    for(let i = 0; i < n - 2; i++) {
        leftSum += nums[i];
        ans = Math.max(ans, leftSum + maxRightSum[i + 2]);
    }
    return ans;

};