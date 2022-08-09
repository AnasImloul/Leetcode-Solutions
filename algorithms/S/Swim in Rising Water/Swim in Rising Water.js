var swimInWater = function(grid) {
    const dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    const heap = new MinPriorityQueue({compare: (a, b) => a.depth - b.depth});
    heap.enqueue({row: 0, col: 0, depth: grid[0][0], maxDepth: grid[0][0]})
    
    let visited = new Set();
    while (heap.size()) {
        let {row, col, maxDepth} = heap.dequeue();
        visited.add(`${row}-${col}`);
        if (row === grid.length - 1 && col === grid.length - 1) return maxDepth;
        for (let [r, c] of dir) {
            let newR = row + r, newC = col + c;
            if (visited.has(`${newR}-${newC}`)) continue;
            if (newR < 0 || newC < 0 || newR >= grid.length || newC >= grid[0].length) continue;
            heap.enqueue({row: newR, col: newC, depth: grid[newR][newC], maxDepth: Math.max(maxDepth, grid[newR][newC])});
        }
    }  
};
