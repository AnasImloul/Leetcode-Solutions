var sumOfDistancesInTree = function(n, edges) {
    let graph = {};
    for (let [start, end] of edges) {
        if (!graph[start]) graph[start] = [];
        if (!graph[end]) graph[end] = [];
        graph[start].push(end);
        graph[end].push(start);
    }
    
    let visited = new Set(), distanceFromZero = 0, totalChildren = {};
    // Find the sum distance from node O to all other nodes and the total children of each node
    function dfs(node, sum = 0) {
        visited.add(node);
        distanceFromZero += sum;
        if (!graph[node]) return;
        let child = 0;
        for (let nextNode of graph[node]) {
            if (visited.has(nextNode)) continue;
            child += dfs(nextNode, sum + 1);
        }
        totalChildren[node] = child;
        return child + 1;
    }
    dfs(0);

    let dp = [distanceFromZero];
    visited = new Set();
    function findDistance(node) {
        visited.add(node);
        if (!graph[node]) return;
        for (let nextNode of graph[node]) {
            if (visited.has(nextNode)) {
                dp[node] = dp[nextNode] + (n - 2);
                break;
            }
        }
        if (node !== 0 && totalChildren[node]) dp[node] -= totalChildren[node] * 2;
        for (let nextNode of graph[node]) {
            if (visited.has(nextNode)) continue;
            else findDistance(nextNode);
        }
    }

    findDistance(0);
    return dp;
};
