// Runtime: 107 ms (Top 61.22%) | Memory: 46.9 MB (Top 57.14%)
var lcaDeepestLeaves = function(root) {
    if(!root) return root;
    // keep track of max depth if node have both deepest node
    let md = 0, ans = null;
    const compute = (r = root, d = 0) => {
        if(!r) {
            md = Math.max(md, d);
            return d;
        }

        const ld = compute(r.left, d + 1);
        const rd = compute(r.right, d + 1);

        if(ld == rd && ld == md) {
            ans = r;
        }

        return Math.max(ld, rd);
    }
    compute();
    return ans;
};