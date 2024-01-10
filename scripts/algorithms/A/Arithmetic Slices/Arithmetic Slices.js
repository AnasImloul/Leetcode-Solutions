// Runtime: 50 ms (Top 70.73%) | Memory: 41.90 MB (Top 54.1%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    if (nums.length < 3) return 0
  
    const diff = []
    
    /* fill our array of differences */
    for (let i = 1; i < nums.length; i++) {
      diff.push(nums[i] - nums[i - 1])
    }

    /* if the first two numbers of our difference array are equal
     * then set our multiplier to 1
     * and also set our "previous" variable to 1
     * otherwise set both to 0 representing no sequence found yet
     */
 
    let multiplier = diff[1] === diff[0] ? 1 : 0
    let dp = diff[1] === diff[0] ? 1 : 0 // our "previous" variable
  
    /* loop thru our differences from idx 2 (0 and 1 have been     
     * accounted for),
     * and check for continuing sequences
     */
    for (let i = 2; i < diff.length; i++) {
      if (diff[i] === diff[i - 1]) { // if equal, increment our multiplier
        multiplier++
      } else { // if not equal, set our multiplier back to 0
        multiplier = 0
      }
      
      dp = dp + 1 * multiplier // recurrence relation
    }

    return dp // our "previous" variable

}
