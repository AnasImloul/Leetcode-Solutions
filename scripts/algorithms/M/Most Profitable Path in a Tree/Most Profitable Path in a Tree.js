// Runtime: 247 ms (Top 100.0%) | Memory: 158.20 MB (Top 64.29%)

var mostProfitablePath = function(edges, bob, amount) {
    const graph = Array.from({ length: edges.length + 1 }, () => []);

    for (const [i, j] of edges)
        graph[i].push(j), graph[j].push(i);
    
    function aliceMoves(node, parent, time) {
        let totalBobTime = node == bob ? 0 : Infinity, newScore = -Infinity;

        for (const child of graph[node]) {
            if (child == parent) continue;

            const [score, bobTime] = aliceMoves(child, node, time + 1);
            totalBobTime = Math.min(totalBobTime, bobTime + 1);
            newScore = Math.max(newScore, score)
        }

        if (newScore == -Infinity) newScore = 0;
        if (time < totalBobTime) newScore += amount[node];
        else if (time == totalBobTime) newScore += amount[node] / 2;

        return [newScore, totalBobTime];
    }
    
    return aliceMoves(0, -1, 0)[0];
};
