var maxProbability = function(n, edges, succProb, start, end) {
    const graph = new Map();
    edges.forEach(([a, b], i) => {
        const aSet = graph.get(a) || [];
        const bSet = graph.get(b) || [];
        aSet.push([b, succProb[i]]), bSet.push([a, succProb[i]]);
        graph.set(a, aSet), graph.set(b, bSet);
    });
    
    const dist = new Array(n).fill(0);
    const vis  = new Array(n).fill(false);
    
    dist[start] = 1;
    
    const getMaxProbNode = () => {
        let maxVal = 0, maxIndex = -1;
        for(let i = 0; i < n; i++) {
            if(maxVal < dist[i] && !vis[i]) {
                maxVal = dist[i], maxIndex = i;
            }
        }
        return maxIndex;
    }
    
    for(let i = 0; i < n - 1; i++) {
        const maxProbNode = getMaxProbNode();
        vis[maxProbNode] = true;
        
        const adjacentNodes = graph.get(maxProbNode) || [];
        const len = adjacentNodes.length;
        for(let j = 0; j < len; j++) {
            const [node, prob] = adjacentNodes[j];
            if(!vis[node] && dist[node] < dist[maxProbNode] * prob) {
                dist[node] = dist[maxProbNode] * prob;
            }
        }
    }
    
    return dist[end];
};
