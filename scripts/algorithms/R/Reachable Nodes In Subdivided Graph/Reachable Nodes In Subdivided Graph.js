var reachableNodes = function(edges, maxMoves, n) {
    const g = Array.from({length: n}, () => []);
    
    for(let [u, v, cnt] of edges) {
        g[u].push([v, cnt + 1]);
        g[v].push([u, cnt + 1]);
    }
    
    // find min budget to reach from 0 to all nodes
    const budget = new Array(n).fill(Infinity);
    budget[0] = 0;
    const dijkstra = () => {
        // heap will be collection [node, weight]
        const heap = new MinPriorityQueue({ priority: (x) => x[1] });
        heap.enqueue([0, 0]);
        while(heap.size()) {
            const [n, c] = heap.dequeue().element;
            for(let [nextNode, cost] of g[n]) {
                let temp = c + cost;
                if(budget[nextNode] > temp) {
                    budget[nextNode] = temp;
                    heap.enqueue([nextNode, temp]);
                }
            }
        }
    };
    dijkstra();
    
    // add to sum all reachable nodes from 0 with max move
    let vis = 0;
    for(let w of budget) vis += w <= maxMoves;

    // add intermediate nodes between edges with available budget
    for(let [a, b, c] of edges) {
        let [availableFromA, availableFromB] = [maxMoves - budget[a], maxMoves - budget[b]];
        if(availableFromA < 0 || availableFromB < 0) {
            vis += Math.max(availableFromA, 0) + Math.max(availableFromB, 0);
        } else {
            const total = availableFromA + availableFromB;
            vis += total - Math.max(total - c, 0);
        }
    }
    
    return vis;
};
