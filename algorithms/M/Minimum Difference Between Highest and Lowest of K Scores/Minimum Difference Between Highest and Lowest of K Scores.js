
```/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumDifference = function(nums, k) {
    nums.sort((a,b)=>a-b)
    let min=nums[0],max=nums[k-1],diff=max-min
    for(let i=k;i<nums.length;i++){
        diff=Math.min(diff,nums[i]-nums[i-k+1])
    }
    return diff
};``