var rotateGrid = function(grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    
    let startRow = 0;
    let endRow = m - 1;
    
    let startCol = 0;
    let endCol = n - 1;
    
    while (startRow <= endRow && startCol <= endCol) {
        let currRowStart = startRow;
        let currRowEnd = endRow;

        let currColStart = startCol;
        let currColEnd = endCol;

        const vals = [];

        // Top
        for (let col = currColStart; col <= currColEnd; ++col) {
            const val = grid[currRowStart][col];
            vals.push(val);
        }
        ++currRowStart;

        // Right
        for (let row = currRowStart; row <= currRowEnd; ++row) {
            const val = grid[row][currColEnd];
            vals.push(val);
        }
        --currColEnd;

        // Bottom
        for (let col = currColEnd; col >= currColStart; --col) {
            const val = grid[currRowEnd][col];
            vals.push(val);
        }
        --currRowEnd;

        // Left
        for (let row = currRowEnd; row >= currRowStart; --row) {
            const val = grid[row][currColStart];
            vals.push(val);
        }
        ++currColStart;

        const size = vals.length;
        const remK = k % size;

        const movedVals = [];

        for (let i = 0; i < size; ++i) {
            const movedIdx = (i + remK) % size;
            movedVals[i] = vals[movedIdx];
        }

        let i = 0;

        currRowStart = startRow;
        currRowEnd = endRow;

        currColStart = startCol;
        currColEnd = endCol;

        // Top
        for (let col = currColStart; col <= currColEnd; ++col) {
            grid[currRowStart][col] = movedVals[i++];
        }
        ++currRowStart;

        // Right
        for (let row = currRowStart; row <= currRowEnd; ++row) {
            grid[row][currColEnd] = movedVals[i++];
        }
        --currColEnd;

        // Bottom
        for (let col = currColEnd; col >= currColStart; --col) {
            grid[currRowEnd][col] = movedVals[i++];
        }
        --currRowEnd;

        // Left
        for (let row = currRowEnd; row >= currRowStart; --row) {
            grid[row][currColStart] = movedVals[i++];
        }
        ++currColStart;

        // update the boundaries for the next layer
        startRow = currRowStart;
        endRow = currRowEnd;

        startCol = currColStart;
        endCol = currColEnd;
    }
    
   return grid;
};
