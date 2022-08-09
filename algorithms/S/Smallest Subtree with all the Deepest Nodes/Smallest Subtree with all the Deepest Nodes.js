var subtreeWithAllDeepest = function(root) {
    // keep track of deepest till now
    // if left right has both deepest than it will be the ans;
    let mx = 0, rm = 0, ans = null;
    const compute = (r = root, d = 0) => {
        if(!r) {
            rm = Math.max(rm, d);
            return d;
        }
        const ld = compute(r.left, d + 1);
        const rd = compute(r.right, d + 1);
        
        if(ld == rd && ld == mx) {
            ans = r;
        }
        if(mx < rm) {
            ans = r;
            mx = rm;
        }
        
        return Math.max(ld, rd);
    }
    compute();
    return ans;
};
