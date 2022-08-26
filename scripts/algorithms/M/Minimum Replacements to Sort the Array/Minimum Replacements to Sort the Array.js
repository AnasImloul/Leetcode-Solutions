// Runtime: 179 ms (Top 13.79%) | Memory: 52.3 MB (Top 70.69%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumReplacement = function(nums) {
    const n = nums.length;
    let ans = 0;
    for(let i = n - 2 ; i >= 0 ; i--){
        if(nums[i]>nums[i+1]){
            const temp = Math.ceil(nums[i]/nums[i+1]);
            ans += temp - 1;
            nums[i] = Math.floor(nums[i]/temp);
        }
    }
    return ans;
};