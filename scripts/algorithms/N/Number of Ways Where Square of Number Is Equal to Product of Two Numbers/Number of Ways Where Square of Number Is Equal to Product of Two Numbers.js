// Runtime: 355 ms (Top 47.37%) | Memory: 61.1 MB (Top 47.37%)
var numTriplets = function(nums1, nums2) {
    const nm1 = new Map(), nm2 = new Map();
    const n = nums1.length, m = nums2.length;
    for(let i = 0; i < n; i++) {
        for(let j = i + 1; j < n; j++) {
            const product = nums1[i] * nums1[j];
            if(!nm1.has(product)) nm1.set(product, 0);
            const arr = nm1.get(product);
            nm1.set(product, arr + 1);
        }
    }
    for(let i = 0; i < m; i++) {
        for(let j = i + 1; j < m; j++) {
            const product = nums2[i] * nums2[j];
            if(!nm2.has(product)) nm2.set(product, 0);
            const arr = nm2.get(product);
            nm2.set(product, arr + 1);
        }
    }
    let ans = 0;

    for(let num of nums1) {
        const sq = num * num;
        if(nm2.has(sq)) {
            ans += nm2.get(sq);
        }
    }
    for(let num of nums2) {
        const sq = num * num;
        if(nm1.has(sq)) {
            ans += nm1.get(sq);
        }
    }
    return ans;
};