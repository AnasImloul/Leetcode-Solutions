var countBits = function(n) {
    if (n === 0) return [0];
    
    const ans = new Array(n + 1).fill(0);
    
    let currRoot = 0;
    for (let idx = 1; idx <= n; idx++) {
        if ((idx & (idx - 1)) === 0) {
            ans[idx] = 1;
            currRoot = idx;
            continue;
        }           
        
        ans[idx] = 1 + ans[idx - currRoot];
    }
    
    return ans;
};
