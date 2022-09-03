// Runtime: 91 ms (Top 47.37%) | Memory: 42.5 MB (Top 31.58%)
var numMovesStones = function(a, b, c) {
    const nums = [a, b, c];

    nums.sort((a, b) => a - b);

    const leftGap = nums[1] - nums[0] - 1;
    const rightGap = nums[2] - nums[1] - 1;

    const maxMoves = leftGap + rightGap;

    if (leftGap == 0 && rightGap == 0) return [0, 0];
    if (leftGap > 1 && rightGap > 1) return [2, maxMoves];
    return [1, maxMoves];
};