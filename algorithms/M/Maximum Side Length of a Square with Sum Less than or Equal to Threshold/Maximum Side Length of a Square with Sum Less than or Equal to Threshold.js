/**
 * @param {number[][]} mat
 * @param {number} threshold
 * @return {number}
 */
var maxSideLength = function(mat, threshold) {
    const n = mat.length, m = mat[0].length;
    
    // build sum matrix
    let sum = [];
    for(let i=0; i<=n; i++) {
        sum.push(new Array(m+1).fill(0));
        for(let j=0; j<=m; j++) {
            if(i==0 || j==0) {
                continue;
            }
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
        }
    }
    
    // function to check square sum <= threshold
    const underThreshold = function(len) {
        for(let i=len; i<=n; i++) {
            for(let j=len; j<=m; j++) {
                if(sum[i][j] - sum[i-len][j] - sum[i][j-len] + sum[i-len][j-len] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    };
    
    // binary search
    let l=0, r=Math.min(n, m);
    while(l<=r) {
        const mid = Math.floor((l+r)/2);
        if(underThreshold(mid)) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return r;
};
