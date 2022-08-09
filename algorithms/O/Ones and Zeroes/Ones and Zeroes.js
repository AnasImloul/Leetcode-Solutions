var findMaxForm = function(strs, m, n) {
    const countZerosAndOne = strs.map(str => {
        let z = 0, o = 0;
        str.split('').forEach(c => c == '0' ? z++ : o++);
        return [z, o];
    });
    const len = strs.length;
    
    const dp = new Map();
    const knapsack = (i, m, n ) => {
        if(i == len) return 0;
        
        const key = i + '#' + m + '#' + n;

        if(dp.has(key)) return dp.get(key);
        
        let pick = 0;
        
        const [rz, ro] = countZerosAndOne[i];
        
        if(m >= rz && n >= ro) pick = knapsack(i + 1, m - rz, n - ro) + 1;
        
        // drop check
        let drop = knapsack(i + 1, m, n);
        
        const op = Math.max(drop, pick);
        dp.set(key, op);
        return op;
    }
    return knapsack(0, m, n);
};
