/**
 * @param {number[][]} points
 * @return {number}
 */

var maxPoints = function(points) {
    if (points.length === 1) {
        return 1;
    }
    
    const slopes = {};
    let dx, dy;
    let xbase, ybase;
    let xref, yref, key;
    const INFINITE_SLOPE = 'infinite';
    
    for(let i = 0; i < points.length; i++) {
        [xbase, ybase] = points[i];
        
        for(let j = i + 1; j < points.length; j++) {                       
            
            [xref, yref] = points[j];
            
            if (xref === xbase) {
                key = `x = ${xref}`;
                
            } else {
                dx = xref - xbase;
                dy = yref - ybase;
                
                let m = dy / dx;
                let c = yref - m * xref;
                
                m = m.toFixed(4);
                c = c.toFixed(4);
                
                key = `y = ${m}x + ${c}`;                
            }
            
            slopes[key] || (slopes[key] = 0);
            slopes[key]++;
        }
    }
    
    const maxPairs = Math.max(...Object.values(slopes));
    
    if (maxPairs === 2) {
        return 2;
    }
    
    for(let i = 1; i <= 300; i++) {
        if (i * (i - 1) / 2 === maxPairs) {
            return i;
        }
    }
    
    return 0;
};
