// Runtime: 93 ms (Top 58.73%) | Memory: 44.4 MB (Top 16.27%)
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let set = new Set(nums1);
    let set2 = new Set(nums2);
    let result = [];
    for (const val of set) {
        if (set2.has(val)) {
            result.push(val);
        }
    }
    return result;
};