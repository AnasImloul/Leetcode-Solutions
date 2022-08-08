var maxLength = function(arr) {
    const bits = [];
    for(let word of arr) {
        let b = 0, flag = true;
        for(let c of word) {
            const idx = c.charCodeAt(0) - 'a'.charCodeAt(0);
            const setBit = (1 << idx);
            if((b & setBit) != 0) {
                flag = false;
                break;
            }
            b = (b ^ setBit);
        }
        if(flag) bits.push(b);
    }
    
    const len = bits.length;
    const dp = new Map();
    const solve = (i = 0, b = 0) => {
        if(i == len) {
            let c = 0;
            while(b > 0) {
                c += (b & 1);
                b >>= 1;
            }
            return c;
        }
        const key = [i, b].join(':');
        if(dp.has(key)) return dp.get(key);
        
        let ans = 0;
        if((b & bits[i]) == 0) {
            // take
            ans = Math.max(ans, solve(i + 1, b | bits[i]));
        }
        ans = Math.max(ans, solve(i + 1, b));
        dp.set(key, ans);
        return ans;
    }
    return solve();
};
