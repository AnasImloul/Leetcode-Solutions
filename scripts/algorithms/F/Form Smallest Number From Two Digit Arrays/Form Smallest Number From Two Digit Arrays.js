// Runtime: 51 ms (Top 81.8%) | Memory: 42.26 MB (Top 56.8%)

var minNumber = function(nums1, nums2) {
    const s1 = new Set(nums1);
    const s2 = new Set(nums2);
    for (let i = 0; i < 10; i++) {
        if (s1.has(i) && s2.has(i)) return i;
    }
    const m1 = Math.min(...nums1);
    const m2 = Math.min(...nums2);
    return +`${Math.min(m1, m2)}${Math.max(m1, m2)}`
};