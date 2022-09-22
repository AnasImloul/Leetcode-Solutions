// Runtime: 73 ms (Top 92.34%) | Memory: 43.5 MB (Top 69.86%)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestSumAfterKNegations = function(nums, k) {
    let negations = k
    let index = 0
    const sortedNums = [...nums]

    // Sort in increasing order
    sortedNums.sort((a, b) => a - b)

    // loop into the sorted array using the
    // number of negations
    while (negations > 0) {
        negations--

        const currentNumber = -sortedNums[index]
        const nextNumber = sortedNums[index + 1]

        sortedNums[index] = currentNumber

        // if the number is 0, undefined or
        // the current number is less than the
        // next number (meaning it will be
        // less the amount if it's a negative
        // number) just use the same number
        // again to flip.
        if (
                currentNumber === 0 ||
                nextNumber === undefined ||
                currentNumber < nextNumber
        ) continue

        index++
    }

    return sortedNums.reduce((sum, num) => sum + num, 0)
};