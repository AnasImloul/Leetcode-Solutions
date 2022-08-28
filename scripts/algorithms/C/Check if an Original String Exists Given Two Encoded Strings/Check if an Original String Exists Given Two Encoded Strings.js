// Runtime: 1300 ms (Top 33.33%) | Memory: 88.9 MB (Top 33.33%)
var possiblyEquals = function(s1, s2) {
    // Memo array, note that we do not need to memoize true results as these bubble up
    const dp = Array.from({length: s1.length+1}, () =>
                          Array.from({length: s2.length+1},
                                     () => ([])));

    const backtrack = (p1, p2, count) => {
        if(p1 === s1.length && p2 === s2.length) return count === 0;
        // Optimization: Exit early if we have already visited here and know that it's false
        if(dp[p1][p2][count] !== undefined) return dp[p1][p2][count];

        let c1 = s1[p1];
        let c2 = s2[p2];

        // Case 1: string matches exactly
        if(p1 < s1.length && p2 < s2.length &&
           c1 === c2 && count === 0 &&
           backtrack(p1+1, p2+1, count)) return true;

        // Case 2: we can delete a character
        if(p1 < s1.length && isNaN(c1) && count < 0 &&
           backtrack(p1+1, p2, count+1)) return true;
        if(p2 < s2.length && isNaN(c2) && count > 0 &&
           backtrack(p1, p2+1, count-1)) return true;

        // Case 3: we can start stacking numbers to delete
        let num = 0;
        for(let i = 0; i < 3 && p1+i < s1.length; i++) {
            let c1 = s1[p1+i];
            if(isNaN(c1)) break;
            num = num * 10 + parseInt(c1);

            if(backtrack(p1+i+1, p2, count + num)) return true;
        }

        num = 0;
        for(let i = 0; i < 3 && p2+i < s2.length; i++) {
            let c2 = s2[p2+i];
            if(isNaN(c2)) break;
            num = num * 10 + parseInt(c2);

            if(backtrack(p1, p2+i+1, count - num)) return true;
        }

        dp[p1][p2][count] = false;
        return false;
    }

    return backtrack(0,0,0);
};