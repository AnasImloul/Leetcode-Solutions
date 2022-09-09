// Runtime: 522 ms (Top 82.69%) | Memory: 89.6 MB (Top 82.69%)
var getAncestors = function(n, edges) {
    const adj = [];
    const ancestors = [];
    const inDegrees = new Array(n).fill(0);

    for (let i = 0 ; i < n; ++i) {
        adj[i] = new Set();
        ancestors[i] = new Set();
    }

    for (const [from, to] of edges) {
        adj[from].add(to);
        ++inDegrees[to];
    }

    const queue = [];

    for (let i = 0 ; i < n; ++i) {
        if (inDegrees[i] === 0) queue.push(i);
    }

    while (queue.length > 0) {
        const node = queue.shift();

        for (const child of adj[node]) {
            --inDegrees[child];

            if (inDegrees[child] === 0) queue.push(child);

            ancestors[child].add(node);
            ancestors[node].forEach((prev) => ancestors[child].add(prev));
        }
    }

    const res = [];

    for (let i = 0; i < n; ++i) {
        res[i] = [...ancestors[i]].sort((a, b) => a - b);
    }

    return res;
};