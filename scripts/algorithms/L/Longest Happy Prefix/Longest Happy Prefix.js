var longestPrefix = function(s) {
    const len = s.length;
    const z = new Array(len).fill(0);
    let l = 0, r = 0;
    
    for(let i = 1; i < len; i++) {
        if(i <= r) 
            z[i] = Math.min(r - i + 1, z[i - l]);
        while(i + z[i] < len && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    
    let idx = -1;
    for(let i = 1; i < len; i++) {
        if(i + z[i] == len) {
            idx = i;
            break;
        }
    }
    if(idx == -1) return '';
    return s.slice(idx);
};
