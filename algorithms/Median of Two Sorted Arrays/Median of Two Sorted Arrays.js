/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
// solution with Binarysearch
var findMedianSortedArrays = function(nums1, nums2) {
	// Check if nums1 is smaller than nums2
    // If not, then we will swap nums1 with nums2
    if(nums1.length > nums2.length)
        return findMedianSortedArrays(nums2, nums1)
    let nums1_length = nums1.length;
    let nums2_length = nums2.length;
    let start = 0;
    let end = nums1_length;
    while(start <= end) {
        let mid_nums1 = Math.floor((start+end)/2)
        let mid_nums2 = Math.floor((nums1_length + nums2_length + 1) / 2) - mid_nums1
        let maxLeft_nums1 = mid_nums1 === 0 ? Number.MIN_SAFE_INTEGER : nums1[mid_nums1 - 1]
        let minRight_nums1 = mid_nums1 === nums1_length ? Number.MAX_SAFE_INTEGER : nums1[mid_nums1]
        
        let maxLeft_nums2 = mid_nums2 === 0 ? Number.MIN_SAFE_INTEGER : nums2[mid_nums2 - 1]
        let minRight_nums2 = mid_nums2 === nums2_length ? Number.MAX_SAFE_INTEGER : nums2[mid_nums2]
        if (maxLeft_nums1 <= minRight_nums2 && maxLeft_nums2 <= minRight_nums1) {
            if ((nums1_length + nums2_length) % 2 == 0) {
                return (Math.max(maxLeft_nums1, maxLeft_nums2) + Math.min(minRight_nums1, minRight_nums2)) / 2.0;
            } else {
                return Math.max(maxLeft_nums1, maxLeft_nums2);
            }
        }
		// we are too far on right so, we want to move to the left of array of the lower length
        else if (maxLeft_nums1 > minRight_nums2) {
            end = mid_nums1 - 1;
        }
        else {
		// we are too far on left so, we want to move to right of array of the lower length
            start = mid_nums1 + 1;
        }
    }
    
}
//===========================================
// another solution without binarySearch
 var findMedianSortedArrays = function(nums1, nums2) {
     let nums = nums1.concat(nums2)
     nums.sort((a,b) => a-b)
     let left=0;
     let right =nums.length -1;
     let mid = Math.floor((left+right)/2)
     let median = 0;
     if(nums.length % 2 === 0)
         median = (nums[mid] + nums[(mid+1)])/2
    else median = nums[mid]
    return median
};

