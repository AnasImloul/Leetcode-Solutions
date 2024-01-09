// Runtime: 71 ms (Top 90.91%) | Memory: 54.30 MB (Top 81.82%)

var minSwap = function(a, b) {
    let n1 = 0, s1 = 1, len = a.length;
    for(let i = 1 ; i < len ; i ++) {
        let n2 = Number.MAX_VALUE, s2 = Number.MAX_VALUE;
        if(a[i-1] < a[i] && b[i-1] < b[i]) {
            n2 = Math.min(n2, n1);
            s2 = Math.min(s2, s1 + 1);
        }
        if(a[i-1] < b[i] && b[i-1] < a[i]) {
            n2 = Math.min(n2, s1);
            s2 = Math.min(s2, n1 + 1);
        }
        n1 = n2;
        s1 = s2;
    }
    return Math.min(n1, s1);
};
