var isPathCrossing = function(path) {
    let set = new Set();
    let curr = [0, 0]
    
    let start = `${curr[0]}, ${curr[1]}`
    set.add(start)
    
    for (let el of path) {
        if (el === 'N') curr[1]++;
        else if (el === 'S') curr[1]--;
        else if (el === 'E') curr[0]++;
        else curr[0]--;
        
        let key = `${curr[0]}, ${curr[1]}`
        if (set.has(key)) return true;
        set.add(key)
    }
    
    return false;
};
