var maximumCandies = function(candies, k) {
    const n = candies.length;
    
    let left = 1;
    let right = 1e7 + 1;
    
    while (left < right) {
        const mid = (left + right) >> 1;
        const pilesAvail = divideIntoPiles(mid);

        if (pilesAvail < k) right = mid;
        else left = mid + 1;
    }
    
    return right - 1;
    
    
    function divideIntoPiles(pileSize) {
        let piles = 0;
        
        for (let i = 0; i < n; ++i) {
            const count = candies[i];
            
            piles += Math.floor(count / pileSize);
        }
        
        return piles;
    }
};
