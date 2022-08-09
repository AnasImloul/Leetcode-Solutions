 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let left = 0;
    let oneCount = 0;
    let maxLength = 0;
    
    for (let right = 0; right < nums.length; right ++) {
        if (nums[right]) {  // so if the element is a 1 since 0 is falsy
            oneCount++
        }
        
        if ((right - left + 1 - oneCount) > k) { // check if we've used all of our replacements
            if (nums[left]) { // start shrinking the window if its a 1 we subtract a count from oneCount
                oneCount--
            }
            left++
        }
        
        maxLength = Math.max(maxLength, right - left + 1); // update maxLength each iteration for largest window
    }
    
    return maxLength
};
