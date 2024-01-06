// Runtime: 99 ms (Top 84.75%) | Memory: 51.20 MB (Top 71.75%)

/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function(graph) {
    const n = graph.length;
    const result = new Array(n).fill(0);

    const dfs = (node) => {
        if (result[node] !== 0) return result[node] === 2;
        result[node] = 1;
        for (let neighbor of graph[node]) {
            if (result[neighbor] === 1 || !dfs(neighbor)) return false;   
        }
        result[node] = 2;
        return true;
    };
    const safeNodes = [];
    for (let node = 0; node < n; node++) {
        if (dfs(node)) safeNodes.push(node);
    
    }
    return safeNodes;
};
