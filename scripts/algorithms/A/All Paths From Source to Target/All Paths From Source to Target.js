/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
const allPathsSourceTarget = function(graph) {
    const n = graph.length;
    const result = [];
    const dfs = (node, path) => {
        if (node === n-1) {
            result.push([...path, node]); // Add the current path to the result if we have reached the target node
            return;
        }
        for (const neighbor of graph[node]) {
            dfs(neighbor, [...path, node]); // Recursively explore all neighbors of the current node
        }
    };
    dfs(0, []); // Start the DFS from the source node
    return result;
};
