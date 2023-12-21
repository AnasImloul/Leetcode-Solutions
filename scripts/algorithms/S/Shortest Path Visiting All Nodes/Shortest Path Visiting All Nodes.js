// Runtime: 92 ms (Top 67.21%) | Memory: 50.60 MB (Top 77.05%)

/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
    const n = graph.length;
    const allVisited = (1 << n) - 1;
    const queue = [];
    const visited = new Set();

    for (let i = 0; i < n; i++) {
        queue.push([1 << i, i, 0]);
        visited.add((1 << i) * 16 + i);
    }

    while (queue.length > 0) {
        const [mask, node, dist] = queue.shift();

        if (mask === allVisited) {
            return dist;
        }

        for (const neighbor of graph[node]) {
            const newMask = mask | (1 << neighbor);
            const hashValue = newMask * 16 + neighbor;

            if (!visited.has(hashValue)) {
                visited.add(hashValue);
                queue.push([newMask, neighbor, dist + 1]);
            }
        }
    }

    return -1;
}
