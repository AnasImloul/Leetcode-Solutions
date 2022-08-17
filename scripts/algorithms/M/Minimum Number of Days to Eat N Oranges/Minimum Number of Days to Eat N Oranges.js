var minDays = function(n) {
    const queue = [ [n,0] ];
    const visited = new Set();
    
    while (queue.length > 0) {
        const [ orangesLeft, days ] = queue.shift();
        
        if (visited.has(orangesLeft)) continue;
        if (orangesLeft === 0) return days;
        
        visited.add(orangesLeft);
        queue.push([orangesLeft - 1, days + 1]);
        
        if (orangesLeft % 2 === 0) {
            queue.push([orangesLeft - orangesLeft / 2, days + 1]);
        }
        
        if (orangesLeft % 3 === 0) {
            queue.push([orangesLeft - 2 * (orangesLeft / 3), days + 1])
        }
    }
};
