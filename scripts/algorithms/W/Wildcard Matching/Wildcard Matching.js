var isMatch = function(s, p) {
    const slen = s.length, plen = p.length;
    const dp   = new Map();
    
    const solve = (si = 0, pi = 0) => {
        // both are compared and are equal till end
        if(si == slen && pi == plen) return true;
        // we have consumed are wildcard string and still s is remaining
        if(pi == plen) return false;
        // we still have wildcard characters remaining
        if(si == slen) {
            while(p[pi] == '*') pi++;
            return pi == plen;
        }
           
        const key = [si, pi].join(':');
        if(dp.has(key)) return dp.get(key);
        
        let ans = false;
        if(p[pi] == '*') {
			// drop * or use it
            ans = solve(si, pi + 1) || solve(si + 1, pi);
        } else {
            const match = s[si] == p[pi] || p[pi] == '?';
            if(match) ans = solve(si + 1, pi + 1);   
        }
        
        dp.set(key, ans);
        
        return ans;
    }
    return solve();
};
