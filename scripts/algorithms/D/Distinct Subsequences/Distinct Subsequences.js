var numDistinct = function(s, t) {
    const n = s.length;

    const memo = {};
    const dfs = (index = 0, subsequence = '') => {
        if(subsequence === t) return 1;
        if(n - index + 1 < t.length - subsequence.length) return 0;
        if(index === n) return 0;

        const key = `${index}-${subsequence}`;
        if(key in memo) return memo[key];

        memo[key] = t[subsequence.length] !== s[index] ? 0 : dfs(index + 1, subsequence + s[index]);
        memo[key] += dfs(index + 1, subsequence);
        return memo[key];
    }

    return dfs();
};
