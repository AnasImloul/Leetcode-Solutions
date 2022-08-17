var findSolution = function(customfunction, z) {
    const result = [];
    
    for(let x = 1; x <= z; x++) {
        for(let y = 1; y <= z; y++) {
            const prod = customfunction.f(x, y);
            if(prod === z) result.push([x, y]);
            if(prod > z) break;
        }
    }
    return result;
};
