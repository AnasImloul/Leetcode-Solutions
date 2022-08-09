var numSub = function(s) {
    const mod = Math.pow(10, 9)+7;
    let r = 0, tot = 0;
    
    while (r<s.length) {
        if (s[r]==='1') {
            let tmp = r;
            while (tmp < s.length && s[tmp] === '1') {
                tot += tmp - r + 1;
                tot%=mod;
                tmp++;
            }
            r = tmp;
        }
        r++;
    }
    return tot;
};
