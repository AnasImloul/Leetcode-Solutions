// Runtime: 161 ms (Top 59.39%) | Memory: 48.4 MB (Top 72.05%)
var findDifference = function(nums1, nums2) {
    const s1 = new Set(nums1);
    const s2 = new Set(nums2);

    const a1 = [...s1].filter(x => !s2.has(x));
    const a2 = [...s2].filter(x => !s1.has(x));

    return [a1, a2];
};