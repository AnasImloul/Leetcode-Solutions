// Runtime: 53 ms (Top 100.0%) | Memory: 47.90 MB (Top 57.14%)

var numSubarrayBoundedMax = function(nums, left, right) {
    let ans = 0, low = 0, mid = 0
    for (let i = 0; i < nums.length; i++) {
        let num = nums[i]
        if (num > right) mid = 0
        else ans += ++mid
        if (num >= left) low = 0
        else ans -= ++low
    }
    return ans
};
