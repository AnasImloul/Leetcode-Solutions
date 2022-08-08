var projectionArea = function(grid) {
    let maxs = new Array(grid.length).fill(0);

    grid.forEach(row => row.forEach((val, idx) => {
        if (maxs[idx] < val) maxs[idx] = val;
    }))
    
    const z = grid.reduce((prev, curr) => prev + curr.filter(val => val !== 0).length, 0);
    const y = grid.reduce((prev, curr) => prev + Math.max(...curr), 0);
    const x = maxs.reduce((prev, curr) => prev + curr, 0)
    
    return x + y + z;
};
