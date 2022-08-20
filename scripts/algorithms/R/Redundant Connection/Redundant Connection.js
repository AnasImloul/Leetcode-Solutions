// Runtime: 123 ms (Top 34.33%) | Memory: 44.8 MB (Top 65.98%)

var findRedundantConnection = function(edges) {
    const root = [];
    const find = (index) => {
        const next = root[index];
        return next ? find(next) : index;
    };

    for (const [a, b] of edges) {
        const x = find(a);
        const y = find(b);

        if (x === y) return [a, b];
        root[x] = y;
    }
};