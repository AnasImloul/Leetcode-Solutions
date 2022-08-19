// Runtime: 205 ms (Top 56.30%) | Memory: 70.4 MB (Top 45.50%)

var goodNodes = function(root) {
    let ans = 0;
    const traverse = (r = root, mx = root.val) => {
        if(!r) return;
        if(r.val >= mx) {
            ans++;
        }
        let childMax = Math.max(mx, r.val);
        traverse(r.left, childMax);
        traverse(r.right, childMax);
    }
    traverse();
    return ans;
};