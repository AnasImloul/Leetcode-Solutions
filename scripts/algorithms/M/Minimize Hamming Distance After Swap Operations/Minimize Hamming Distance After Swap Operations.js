var minimumHammingDistance = function(source, target, allowedSwaps) {
    const n = source.length;
    
    const uf = {};
    const sizes = {};
    const members = {};
    
    // initial setup
    for (let i = 0; i < n; i++) {
        const srcNum = source[i];
        
        uf[i] = i;
        sizes[i] = 1;
        members[i] = new Map();
        members[i].set(srcNum, 1);
    }
    
    function find(x) {
        if (uf[x] != x) uf[x] = find(uf[x]);
        return uf[x];
    }
    
    function union(x, y) {
        const rootX = find(x);
        const rootY = find(y);
        
        if (rootX === rootY) return;
        
        if (sizes[rootX] > sizes[rootY]) {
            uf[rootY] = rootX;
            sizes[rootX] += sizes[rootY];
            
            for (const [num, count] of members[rootY]) {
                if (!members[rootX].has(num)) members[rootX].set(num, 0);
                members[rootX].set(num, members[rootX].get(num) + count);
            }
        }
        else {
            uf[rootX] = rootY;
            sizes[rootY] += sizes[rootX];

            const num = source[x];

            for (const [num, count] of members[rootX]) {
                if (!members[rootY].has(num)) members[rootY].set(num, 0);
                members[rootY].set(num, members[rootY].get(num) + count);
            }
        }
    }
    
    for (const [idx1, idx2] of allowedSwaps) {
        union(idx1, idx2);
    }
    
    let mismatches = 0;
    
    for (let i = 0; i < n; i++) {
        const srcNum = source[i];
        const tarNum = target[i];
        
        const group = find(i);
        
        if (members[group].has(tarNum)) {
            members[group].set(tarNum, members[group].get(tarNum) - 1);
            if (members[group].get(tarNum) === 0) members[group].delete(tarNum);
        }   
        else {
            mismatches++;
        }
    }
    
    return mismatches;
};
