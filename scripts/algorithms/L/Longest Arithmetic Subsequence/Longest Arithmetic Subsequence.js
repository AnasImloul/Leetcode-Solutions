// Runtime: 1333 ms (Top 78.26%) | Memory: 101.5 MB (Top 15.22%)
var longestArithSeqLength = function(nums) {
    if (nums === null || nums.length === 0) {
        return 0;
    }
    let diffMap = new Array(nums.length).fill(0).map(() => new Map());
    let maxLen = 1;
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            let diff = nums[i] - nums[j];
            // if prev element has an ongoing arithmetic sequence with the same common difference
            // we simply add 1 to the length of that ongoing sequence, hence diffMap[j].get(diff) + 1
            // else, we start a new arithmetic sequence, initial length is 2
            diffMap[i].set(diff, diffMap[j].get(diff) + 1 || 2);
            maxLen = Math.max(maxLen, diffMap[i].get(diff));
        }
    }
    return maxLen;
    // T.C: O(N^2)
    // S.C: O(N^2)
};