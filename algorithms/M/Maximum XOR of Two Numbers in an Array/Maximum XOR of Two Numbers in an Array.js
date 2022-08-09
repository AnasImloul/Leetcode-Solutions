var findMaximumXOR = function(nums) {
    const trie = {};
    const add = (num) => {
        let p = trie;
        for(let i = 31; i >= 0; i--) {
            const isSet = (num >> i) & 1;
            if(!p[isSet]) p[isSet] = {};
            p = p[isSet];
        }
    }
    const xor = (num) => {
        let p = trie;
        let ans = 0;
        for(let i = 31; i >= 0; i--) {
            const isSet = ((num >> i) & 1);
            const opp = 1 - isSet;
            const hasOpp = p[opp];
            if(hasOpp) {
                ans = ans | (1<<i);
                p = p[opp];
            } else {
                p = p[isSet];
            }
        }
        return ans;
    }
    
    for(let num of nums) {
        add(num);
    }
    let max = 0;
    for(let num of nums) {
        max = Math.max(max, xor(num))
    }
    return max;
};
