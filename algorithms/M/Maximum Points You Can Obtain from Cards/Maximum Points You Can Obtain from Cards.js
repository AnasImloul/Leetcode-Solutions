/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */

// Obtaining k cards from the beginning or end of the row for the largest sum, meaning leaving the
// array with n-k adjacent cards with the min sum
// therefore, this transform the problem to finding the minSum of subarray of length n-k
// we use slide window to calculate the minSubArraySum
var maxScore = function(cardPoints, k) {
    const n = cardPoints.length, d = n-k // d is the window length
    let sum = 0
    for (let i = 0; i < d; i++) {
        sum += cardPoints[i]
    }
    let minWindowSum = sum, totalSum = sum
    console.log(sum)
    for (let i = d; i < n; i++) {
        // the sum of the next window will the the sum of previous window + the next card (the end card of the next window) - the beginning card of the previous window
        sum += cardPoints[i] - cardPoints[i-d]
        minWindowSum = Math.min(minWindowSum, sum)
        totalSum += cardPoints[i]
    }
    // the ans will be the sum of all cards - the sum of min subArray
    return totalSum - minWindowSum
};
