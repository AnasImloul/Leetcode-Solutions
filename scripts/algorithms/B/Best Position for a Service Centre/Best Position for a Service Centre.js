/**
 * @param {number[][]} positions
 * @return {number}
 */
var getMinDistSum = function(positions) {
    /**
      identify the vertical range and horizontal range
      
      start from the center of positions
      calc the distance
        test the 4 direction with a certain step
            if any distance is closer, choose it as the new candidate
        if all 4 are further, reduce the step
    **/
    
    
    let xSum = 0;
    let ySum = 0;
    for (const [x, y] of positions) {
        xSum += x;
        ySum += y;
    }
    
    let n = positions.length;
    let x = xSum / n;
    let y = ySum / n;
    
    let step = 0.5;
    const dirs = [[0, 1], [0, -1], [-1, 0], [1, 0]];
    while (step >= 10 ** -5) {
        
        const dist = calcDist(x, y);
        let found = false;
        for (const [xDiff, yDiff] of dirs) {
            const newX = x + xDiff * step;
            const newY = y + yDiff * step;
            const newDist = calcDist(newX, newY);
            
            // console.log(x, y, newDist, dist);
            if (newDist < dist) {
                x = newX;
                y = newY;
                found = true;
                break;
            }
        }
        
        if (!found) {
            step /= 2;
        }
    }
    
    return calcDist(x, y);
    
    
    function calcDist(x, y) {
        let dist = 0;
        for (const [posX, posY] of positions) {
            dist += Math.sqrt((x - posX) ** 2 + (y - posY) ** 2);
        }
        return dist;
    }
};
