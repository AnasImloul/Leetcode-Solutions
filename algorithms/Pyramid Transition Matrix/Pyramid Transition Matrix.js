var pyramidTransition = function(bottom, allowed) {
    const set = new Set(allowed);
    const memo = new Map();
    const chars = ["A", "B", "C", "D", "E", "F"];
    
    return topDown(bottom, bottom.length - 1);
    
    function topDown(prev, row) {
        const key = `${prev}#${row}`;
        
        if (row === 0) return true;
        if (memo.has(key)) return memo.get(key);

        let pats = new Set();
        pats.add("");

        for (let i = 0; i < row; i++) {
            const tmp = new Set();

            const leftBot = prev.charAt(i);
            const rightBot = prev.charAt(i + 1);

            for (const char of chars) {
                const triadStr = leftBot + rightBot + char;

                if (set.has(triadStr)) {
                    for (const pat of pats) {
                        tmp.add(pat + char);
                    }                 
                }
            }
          
            pats = tmp;
        }
        
        for (const pat of pats) {
            if (topDown(pat, row - 1)) return true;
        }
        
        memo.set(key, false);
        return false;
    }
};
