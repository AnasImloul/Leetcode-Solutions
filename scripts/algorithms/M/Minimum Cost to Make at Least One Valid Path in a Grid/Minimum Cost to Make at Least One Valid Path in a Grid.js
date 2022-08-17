var minCost = function(grid) {
    const m = grid.length, n = grid[0].length;
    const vis = Array.from({ length: m}, () => {
        return new Array(n).fill(false);
    });
    const dir = [
        [0, 1, 1],
        [0, -1, 2],
        [1, 0, 3],
        [-1, 0, 4]
    ];
    
    const heap = new MinPriorityQueue({
        priority: x => x[0]
    });
    
    heap.enqueue([0, 0, 0]);
    const isInside = (x, y) => {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    while(heap.size()) {
        const [dis, x, y] = heap.dequeue().element;
        if(x == m - 1 && y == n - 1) return dis;
        
        if(vis[x][y]) continue;
        vis[x][y] = true;
        
        for(let [a, b, dr] of dir) {
            a += x, b += y;
            if(!isInside(a, b)) continue;
            heap.enqueue(
                [dis + (grid[x][y] != dr),a, b]
            )
        }
    }
};
