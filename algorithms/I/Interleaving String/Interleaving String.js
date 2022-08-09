var isInterleave = function(s1, s2, s3) {
    const dp = new Map();
    const solve = (a = 0, b = 0, c = 0) => {
        if(c == s3.length) return a == s1.length && b == s2.length;
        const key = [a, b, c].join(':');
        
        if(dp.has(key)) {
            // console.log('hit');
            return dp.get(key);
        }
        
        let takeS1 = false, takeS2 = false;
        if(s1[a] == s3[c]) takeS1 = solve(a + 1, b, c + 1);
        if(s2[b] == s3[c]) takeS2 = solve(a, b + 1, c + 1);

        dp.set(key, takeS1 || takeS2);
        return takeS1 || takeS2;
    }
    return solve();
};
