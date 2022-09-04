// Runtime: 112 ms (Top 7.14%) | Memory: 41.7 MB (Top 57.14%)
var movesToMakeZigzag = function(nums) {
    const n = nums.length;

    let lastEvenRight = Number.MIN_SAFE_INTEGER;
    let evenMoves = 0;

    let lastOddRight = nums[0];
    let oddMoves = 0;

    for (let i = 0; i < n; i++) {
        const currNum = nums[i];
        const nextNum = i < n - 1 ? nums[i + 1] : Number.MIN_SAFE_INTEGER;

        if (i % 2 === 0) {
            if (lastEvenRight >= currNum) evenMoves += lastEvenRight - currNum + 1;

            if (currNum <= nextNum) {
                evenMoves += nextNum - currNum + 1;
            }

            lastEvenRight = Math.min(currNum - 1, nextNum);
        }
        else {
            if (lastOddRight >= currNum) oddMoves += lastOddRight - currNum + 1;

            if (currNum <= nextNum) {
                oddMoves += nextNum - currNum + 1;
            }

            lastOddRight = Math.min(currNum - 1, nextNum);
        }
    }

    return Math.min(oddMoves, evenMoves);
};