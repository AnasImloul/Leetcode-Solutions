var pseudoPalindromicPaths  = function(root) {
    if(!root) return 0;
    // if even it's zero or it's power of two when odd
    const ways = (r = root, d = 0) => {
        if(!r) return 0;
        d = d ^ (1 << r.val);
        // leaf
        if(r.left == r.right && r.left == null) {
            const hasAllEven = d == 0;
            const hasOneOdd = (d ^ (d & -d)) == 0;
            return Number(hasEven || hasOneOdd);
        }
        return ways(r.left, d) + ways(r.right, d);
    }
    return ways();
};
