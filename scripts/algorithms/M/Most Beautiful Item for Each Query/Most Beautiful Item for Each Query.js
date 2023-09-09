// Runtime: 192 ms (Top 92.3%) | Memory: 78.58 MB (Top 69.2%)

var maximumBeauty = function(items, queries) {
    items.sort((a,b) => a[0]-b[0]);
    const n = items.length;
    
    
    let mx = items[0][1];
    
    for (let i = 0; i<n; i++) {
        mx = Math.max(mx, items[i][1]);
        items[i][1] = mx;
    }
    
    
    const ans = [];
    
    for (const q of queries) {
        let l = 0, r = n-1, a = 0;
        while (l<=r) {
            let mid = Math.floor(l+(r-l)/2);
            if (items[mid][0]<=q) {
                a = items[mid][1]
                l = mid+1;
            } else r = mid-1;
        }
        ans.push(a)
    }
    
    return ans;
};