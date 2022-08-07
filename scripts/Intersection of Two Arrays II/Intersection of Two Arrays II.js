/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    // initialize empty array
    let result = [];
    
    // sort arrays
    const nums1Sorted = nums1.sort((a,b) => a - b);
    const nums2Sorted = nums2.sort((a,b) => a - b);
    
    let i = 0;
    let j = 0;
    
    while(i < nums1Sorted.length && j < nums2Sorted.length ){
        // if nums1 index value is smaller than nums2 index value continue interating through nums1
       if(nums1Sorted[i] < nums2Sorted[j]){
           i++;
        // if nums1 index value is larger than nums2 index value continue interating through nums2
       }else if(nums1Sorted[i] > nums2Sorted[j]){
           j++;
       }else{
           // if match found, push to result
           result.push(nums1Sorted[i]);
           i++;
           j++;
       }
    }
    return result;
    
};
