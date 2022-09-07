// Runtime: 117 ms (Top 31.87%) | Memory: 45.8 MB (Top 47.25%)
var maxAncestorDiff = function(root) {
    let ans = 0;
    const traverse = (r = root, mx = root.val, mn = root.val) => {
        if(!r) return;
        ans = Math.max(ans, Math.abs(mx - r.val), Math.abs(mn - r.val));
        mx = Math.max(mx, r.val);
        mn = Math.min(mn, r.val);
        traverse(r.left, mx, mn);
        traverse(r.right, mx, mn);
    }
    traverse();
    return ans;
};