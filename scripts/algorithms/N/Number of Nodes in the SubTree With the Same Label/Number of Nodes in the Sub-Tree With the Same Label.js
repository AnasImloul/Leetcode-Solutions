// Runtime: 934 ms (Top 75.00%) | Memory: 180.7 MB (Top 62.50%)
var countSubTrees = function(n, edges, labels) {
    const adj = [];

    for (let i = 0; i < n; i++) {
        adj[i] = [];
    }

    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    const resCount = new Array(n).fill(0);

    dfs(0, -1);

    return resCount;

    function dfs(node, parent) {
        const label = labels.charCodeAt(node) - 97;

        const charCount = new Array(26).fill(0);

        charCount[label] = 1;

        for (const childNode of adj[node]) {
            if (childNode == parent) continue;

            const subCount = dfs(childNode, node);

            for (let i = 0; i < 26; i++) {
                charCount[i] += subCount[i];
            }
        }

        resCount[node] = charCount[label];
        return charCount;
    }
}