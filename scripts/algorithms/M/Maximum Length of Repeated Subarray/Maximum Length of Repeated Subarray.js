// Runtime: 560 ms (Top 30.97%) | Memory: 88.4 MB (Top 38.43%)
var findLength = function(nums1, nums2) {
    let dp = new Array(nums1.length+1).fill(0).map(
        () => new Array(nums2.length+1).fill(0)
    )
    let max = 0;
    for (let i = 0; i < nums1.length; i++) {
        for (let j = 0; j < nums2.length; j++) {
            if (nums1[i] != nums2[j]) {
                continue;
            }
            dp[i+1][j+1] = dp[i][j]+1;
            max = Math.max(max, dp[i+1][j+1]);
        }
    }

    return max;
};