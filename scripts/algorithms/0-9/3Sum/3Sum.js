// Runtime: 250 ms (Top 39.42%) | Memory: 52.7 MB (Top 62.36%)

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a, b) => a - b);

    const ans = [];

    for (let i = 0; i < nums.length - 2; i++) {
        if (i === 0 || nums[i - 1] !== nums[i]) {
            let j = i + 1;
            let k = nums.length - 1;
            while (j < k) {
                if (nums[j] + nums[k] === -nums[i]) {
                    ans.push([nums[i], nums[j], nums[k]]);
                    j++;
                    while(j < k && nums[j - 1] === nums[j]) j++;
                    k--;
                    while(k > -1 && nums[k] === nums[k + 1]) k--;
                } else if (nums[j] + nums[k] < -nums[i]) {
                    j++;
                } else {
                    k--;
                }
            }
        }
    }

    return ans;
};