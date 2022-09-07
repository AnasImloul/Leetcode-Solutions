// Runtime: 132 ms (Top 59.47%) | Memory: 49 MB (Top 28.57%)
/**
 * 1. compute all positions for each number
 * 2. filter arrays of max length
 * 3. select minimum difference between its first and last elems
 */
var findShortestSubArray = function(nums) {
    const numPositions = {};
    for (let i=0; i<nums.length; i++) {
        const num = nums[i];
        if (numPositions[num] == null) numPositions[num] = [];
        numPositions[num].push(i);
    }

    let maxLen = 0;
    // will store the positions of most frequent numbers
    let maxPos = [];
    for (const positions of Object.values(numPositions)) {
        const curLen = positions.length;
        if (curLen === maxLen) {
            maxPos.push(positions);
        } else if (curLen > maxLen) {
            maxLen = curLen;
            maxPos = [positions]
        }
    }

    let minDist = Number.MAX_SAFE_INTEGER;
    for (const positions of maxPos) {
        minDist = Math.min(minDist, positions[positions.length-1] - positions[0] + 1);
    }
    return minDist;
};