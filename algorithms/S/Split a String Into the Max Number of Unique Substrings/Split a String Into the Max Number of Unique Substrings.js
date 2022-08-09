var maxUniqueSplit = function(s) {
    let wordSet = new Set(), res = 1;
    
    function checkUniqueSubstring(i) {
        if (i === s.length) {
            res = Math.max(wordSet.size, res);
            return;
        }
        
        for (let j = i+1; j <= s.length; j++) {
            let str = s.substring(i,j);
            if (!wordSet.has(str)) {
                wordSet.add(str);
                checkUniqueSubstring(j);
                wordSet.delete(str);
            }
        }
    }
    
    checkUniqueSubstring(0);
    
    return res;
};
