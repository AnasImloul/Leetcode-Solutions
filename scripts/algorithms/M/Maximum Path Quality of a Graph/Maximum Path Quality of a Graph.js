// Runtime: 529 ms (Top 73.33%) | Memory: 57.2 MB (Top 26.67%)
var maximalPathQuality = function(values, edges, maxTime) {
    const adjacencyList = values.map(() => []);
    for (const [node1, node2, time] of edges) {
        adjacencyList[node1].push([node2, time]);
        adjacencyList[node2].push([node1, time]);
    }

    const dfs = (node, quality, time, seen) => {
        // if we returned back to the 0 node, then we log it as a valid value
        let best = node === 0 ? quality : 0;

        // try to visit all the neighboring nodes within the maxTime
        // given while recording the max
        for (const [neighbor, routeTime] of adjacencyList[node]) {
            const totalTime = time + routeTime;
            if (totalTime > maxTime) continue;
            if (seen.has(neighbor)) {
                best = Math.max(best,
                                dfs(neighbor, quality, totalTime, seen));
            } else {
                seen.add(neighbor);
                best = Math.max(best,
                                dfs(neighbor, quality + values[neighbor], totalTime, seen));
                seen.delete(neighbor);
            }
        }
        return best;
    }
    return dfs(0, values[0], 0, new Set([0]));
};