var twoOutOfThree = function(nums1, nums2, nums3) {
    let newArr = [];
    newArr.push(...nums1.filter(num => nums2.includes(num) || nums3.includes(num)))
    newArr.push(...nums2.filter(num => nums1.includes(num) || nums3.includes(num)))
    return Array.from(new Set(newArr))
};
