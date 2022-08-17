var maxConsecutive = function(bottom, top, special) {
    special.push(top + 1, bottom - 1);
    special.sort((a, b) => a - b);
    
    const n = special.length;
    
    let max = 0;
    
    for (let i = 1; i < n; ++i) {
        const curr = special[i];
        const prev = special[i - 1];
        const between = curr - prev - 1;
        
        max = Math.max(max, between);
    }
    
    return max;
};
