// Runtime: 497 ms (Top 62.5%) | Memory: 184.40 MB (Top 50.0%)

var networkBecomesIdle = function(edges, patience) {
    let graph = {};
    for (let [edge, neighbor] of edges) {
        if (!(edge in graph)) graph[edge] = [];
        graph[edge].push(neighbor);
        if (!(neighbor in graph)) graph[neighbor] = [];
        graph[neighbor].push(edge);
    }

    // Initialize queue with server 0
    let q = [0];
	let seconds = 0, complete = {};
    while (q.length) {
        let newQ = [];
        while (q.length) {
            let current = q.pop();
            if (current in complete) continue;
            complete[current] = seconds * 2;
            for (let edge of graph[current]) {
                if (complete[edge]) continue;
                newQ.push(edge);
            }
        }
        q = newQ;
        seconds++;
    }
    
    // Total servers
    let servers = Object.keys(graph).length;
    
    let maxSeconds = 0;
    for (let i = 1; i < servers; i++) {
        let timeToComplete = complete[i];
        let resendInterval = patience[i];
        
        // If timeToComplete == 4 and resendInterval == 2, the msg will be resent 1 time at second 2 and not second 4
        // If timeToComplete == 5 and resendInterval == 2, the msg will be resent 2 times at second 2 and second 4
        // Hence we use Math.ceil(...) - 1
        let resendCount = Math.ceil(timeToComplete / resendInterval) - 1;
        
        let seconds = timeToComplete + (resendInterval * resendCount);
        maxSeconds = Math.max(maxSeconds, seconds);
    }
    return maxSeconds + 1;
};
