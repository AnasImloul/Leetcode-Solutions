var bestCoordinate = function(towers, radius) {
    const n = towers.length;
    const grid = [];
    
    for (let i = 0; i <= 50; i++) {
        grid[i] = new Array(51).fill(0);
    }
    
    
    for (let i = 0; i < n; i++) {
        const [x1, y1, quality1] = towers[i];
        
        for (let x2 = 0; x2 <= 50; x2++) {
            for (let y2 = 0; y2 <= 50; y2++) {
                const dist = Math.sqrt((x1 - x2)**2 + (y1 - y2)**2);

                if (dist > radius) continue;

                const network = Math.floor(quality1 / (1 + dist));
                
                grid[x2][y2] += network;
            }
        }
    }
    
	
    let maxX = 0;
    let maxY = 0;
    let maxVal = grid[0][0];
    
    for (let i = 0; i <= 50; i++) {
        for (let j = 0; j <= 50; j++) {
            const val = grid[i][j];
            
            if (val > maxVal) {
                maxVal = val;
                maxX = i;
                maxY = j;
            }
            else if (val === maxVal) {
                if (i < maxX || (i === maxX && j < maxY)) {
                    maxVal = val;
                    maxX = i;
                    maxY = j;
                }
            }
        }
    }
    
    return [maxX, maxY];
};
