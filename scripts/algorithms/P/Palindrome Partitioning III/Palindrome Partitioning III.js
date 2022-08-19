// Runtime: 193 ms (Top 16.67%) | Memory: 45.6 MB (Top 100.00%)

var palindromePartition = function(s, k) {
    const len = s.length;

    const cost = (i = 0, j = 0) => {
        let c = 0;
        while(i <= j) {
            if(s[i] != s[j]) c++;
            i++, j--;
        }
        return c;
    }

    const dp = Array.from({ length: len }, () => {
        return new Array(k + 1).fill(-1);
    })

    const splitHelper = (idx = 0, sl = k) => {
        if(sl < 0) return Infinity;
        if(idx == len) {
            if(sl == 0) return 0;
            return Infinity;
        }

        if(dp[idx][sl] != -1) return dp[idx][sl];

        let ans = Infinity;

        for(let i = idx; i < len; i++) {
            ans = Math.min(ans, splitHelper(i + 1, sl - 1) + cost(idx, i));
        }
        return dp[idx][sl] = ans;
    }

    return splitHelper();
};