// Runtime: 102 ms (Top 33.33%) | Memory: 41.9 MB (Top 84.85%)
var findDifferentBinaryString = function(nums) {
    return nums.map((s, i) => s[i] == 1 ? '0' : '1').join('');
};