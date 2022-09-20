// Runtime: 272 ms (Top 14.02%) | Memory: 62.9 MB (Top 24.30%)
var allPossibleFBT = function(n) {
    if(n % 2 == 0) return [];
    if( n == 1 ) return [new TreeNode(0)];
    const ans = [];

    const generate = (x) => {
        if(x == 1) return [new TreeNode(0)];
        const ans = [];
        for(let l = 1; l <= x - 2; l += 2) {
            const left = generate(l);
            const right = generate(x - 1 - l);
            left.forEach(l => {
                right.forEach(r => {
                    const root = new TreeNode(0);
                    root.left = l;
                    root.right = r;
                    ans.push(root);
                });
            });
        }
        return ans;
    }

    for(let l = 1; l <= n - 2; l += 2) {
        const left = generate(l);
        const right = generate(n - 1 - l);
        left.forEach(l => {
            right.forEach(r => {
                const root = new TreeNode(0);
                root.left = l;
                root.right = r;
                ans.push(root);
            });
        });
    }

    return ans;
};