var digArtifacts = function(n, artifacts, dig) {
    const set = new Set();
    
    for (const [row, col] of dig) {
        set.add(getCoord(row, col));
    }
    
    let count = 0;
    
    for (let i = 0; i < artifacts.length; ++i) {
        const [startRow, startCol, endRow, endCol] = artifacts[i];
        
        let extracted = true;
        
        for (let row = startRow; row <= endRow; ++row) {
            for (let col = startCol; col <= endCol; ++col) {
                const coord = getCoord(row, col);        
        
                if (!set.has(coord)) {
                    extracted = false;
                    break;
                }
            }
        }
        
        if (extracted) ++count;
        
    }
    
    return count;
    
    function getCoord(row, col) {
        return `${row}#${col}`;
    }
};
