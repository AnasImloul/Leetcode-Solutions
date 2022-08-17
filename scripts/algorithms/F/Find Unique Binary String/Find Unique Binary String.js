var findDifferentBinaryString = function(nums) {
    return nums.map((s, i) => s[i] == 1 ? '0' : '1').join('');
};
