// Runtime: 232 ms (Top 93.36%) | Memory: 57.4 MB (Top 48.67%)
/**
 * The buckets solution.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    const n = nums.length

    if (n < 2) {
        return 0
    }

    if (n < 3) {
        return Math.abs(nums[0] - nums[1])
    }

    let maxNum = -Infinity
    let minNum = +Infinity

    for (let i = 0; i < n; i++) {
        maxNum = Math.max(maxNum, nums[i])
        minNum = Math.min(minNum, nums[i])
    }

    if (maxNum === minNum) {
        return 0
    }

    const k = n - 1
    const averageGap = (maxNum - minNum) / k

    const minBuckets = new Array(k)
    const maxBuckets = new Array(k)

    minBuckets[0] = minNum
    maxBuckets[0] = minNum

    minBuckets[k - 1] = maxNum
    maxBuckets[k - 1] = maxNum

    for (let i = 0; i < n; i++) {
        if (minNum === nums[i] || nums[i] === maxNum) {
            continue
        }

        const j = Math.floor((nums[i] - minNum) / averageGap)

        minBuckets[j] = minBuckets[j] ? Math.min(minBuckets[j], nums[i]) : nums[i]
        maxBuckets[j] = maxBuckets[j] ? Math.max(maxBuckets[j], nums[i]) : nums[i]
    }

    let largestGap = 0
    let prevMaxIndex = 0

    for (let i = 1; i < n - 1; i++) {
        if (minBuckets[i]) {
            largestGap = Math.max(largestGap, minBuckets[i] - maxBuckets[prevMaxIndex])
        }

        if (maxBuckets[i]) {
            prevMaxIndex = i
        }
    }

    return largestGap
}