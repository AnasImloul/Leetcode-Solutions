// Runtime: 104 ms (Top 50.41%) | Memory: 44.1 MB (Top 53.95%)
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    // [Value, Index] of all numbers in nums2
    const indexMap = new Map()
    for(let i = 0; i < nums2.length; i++){
        indexMap.set(nums2[i], i)
    }

    // Stores the next greatest elements
    let result = []

    // Iterate through all the numbers of interest. Remember that all numbers in nums1 are present in nums2.
    for(let num of nums1){

        // Check to see those numbers were present in the nums2 indexMap
        if(indexMap.has(num)){

            // If they were, we must find the next greatest element.
            // Set it to -1 by default in case we cannot find it.
            let nextGreatest = -1

            // Iterate through all numbers in nums2 to the right of the index of the target number. (index of the target + 1)
            for(let i = indexMap.get(num) + 1; i < nums2.length; i++){
                // Check to see if the current number is greater than the target.
                if(nums2[i] > num){
                    // If it is, this is the next greatest element.
                    nextGreatest = nums2[i]
                    // Break the loop.
                    break;
                }
            }
            // Add the next greatest element (if found). Otherwise, add -1 (default)
            result.push(nextGreatest)
        }
    }

    // Return the array of next greatest elements.
    return result
};