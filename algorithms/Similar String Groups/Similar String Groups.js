var numSimilarGroups = function(strs) {
    const len = strs.length;
    
    // dsu logic
    const dsu = new Array(len).fill(0).map((_, idx) => idx);
    const find = (x) => {
        if(x == dsu[x]) return x;
        return dsu[x] = find(dsu[x]);
    }
    const union = (i, j) => {
        const pi = find(i);
        const pj = find(j);
        if(pi != pj) {
            dsu[pi] = pj;
        }
    }
    
    
    const similar = (a, b) => {
        let c = 0, i = 0, len = a.length;
        while(i < len) {
            if(a[i] != b[i]) c++;
            i++;
            if(c > 2) return false;
        }
        return true;
    }
    
    for(let i = 0; i < len; i++) {
        for(let j = i + 1; j < len; j++) {
            if(similar(strs[i], strs[j])) {
                union(i, j);
            }
        }
    }
    for(let i = 0; i < len; i++) find(i);
    const s = new Set();
    for(let i = 0; i < len; i++) s.add(dsu[i]);
    return s.size;
};
