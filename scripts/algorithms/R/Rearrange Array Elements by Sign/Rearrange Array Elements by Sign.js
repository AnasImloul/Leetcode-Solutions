// Runtime: 261 ms (Top 95.19%) | Memory: 96.70 MB (Top 54.92%)

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    let result = [];
    let l=0;
    let r=0;
    while(result.length !== nums.length){
         while( nums[l]< 0){
              l++
          }
        while( nums[r]> 0){
              r++
         }
        
        result.push(nums[l], nums[r]);
        l++;
        r++;
    }
    return result
    
};
