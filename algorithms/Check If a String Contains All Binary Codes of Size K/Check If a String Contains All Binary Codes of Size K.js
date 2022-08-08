/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var hasAllCodes = function(s, k) {
    
    if (k > s.length) {
        return false;
    }
    
    /* Max strings can be generated of k chars 0/1. */
    const max = Math.pow(2, k);
    
    /*
    * Create a set. 
    * It will contain all unique values.
    */ 
    const set = new Set();
    
    for(let i = 0; i < s.length - k + 1; i++) {
        /* Generate substring of size k from index i */
        const substr = s.substr(i, k);        
        set.add(substr);
        
        /* 
        * if enough of unique strings are generated, 
        * break the loop as there is no point of iterating
        * as we have found all necessary strings.
        */
        if (set.size === max) {
            return true;
        }
    }
          
    return set.size === max;
};
