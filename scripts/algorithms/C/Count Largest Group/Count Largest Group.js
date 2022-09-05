// Runtime: 146 ms (Top 27.63%) | Memory: 47.5 MB (Top 55.26%)
var countLargestGroup = function(n) {
    const hash = {};

    for (let i = 1; i <= n; i++) {
        const sum = i.toString().split('').reduce((r, x) => r + parseInt(x), 0);

        if (!hash[sum]) {
            hash[sum] = 0;
        }

        hash[sum]++;
    }

    return Object.keys(hash)
        .sort((a, b) => hash[b] - hash[a])
        .reduce((res, x) => {
            const prev = res[res.length - 1];

            if (!prev || prev === hash[x]) {
                res.push(hash[x]);
            }

            return res;
        }, []).length;
};