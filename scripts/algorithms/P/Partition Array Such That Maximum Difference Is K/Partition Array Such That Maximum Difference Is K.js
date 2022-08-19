// Runtime: 322 ms (Top 36.23%) | Memory: 54.6 MB (Top 31.88%)

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var partitionArray = function(nums, k) {

    nums.sort((a,b) =>{ return a-b})

    let n = nums.length ,ans=0

    for(let i=0 ; i<n; i++){
        let ele = nums[i]
        while(i<n && nums[i]-ele<=k) i++
        i--
        ans++
    }
    return ans
};