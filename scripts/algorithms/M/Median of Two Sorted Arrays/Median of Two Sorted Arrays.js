var findMedianSortedArrays = function(nums1, nums2) {
  let nums3 = nums1.concat(nums2).sort((a,b) => a - b)
  if(nums3.length % 2 !== 0) return nums3[(nums3.length-1)/2]
  return (nums3[nums3.length/2] + nums3[nums3.length/2 - 1])/2
};
