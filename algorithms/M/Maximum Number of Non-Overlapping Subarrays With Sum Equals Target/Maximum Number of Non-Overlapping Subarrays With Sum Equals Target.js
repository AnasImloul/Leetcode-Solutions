var maxNonOverlapping = function(nums, target) {
    const seen = new Set();
    let total = 0, result = 0;
    
    for(let n of nums) {
        total += n;
        
        if(total === target || seen.has(total - target)) {
            total = 0;
            result++;
            seen.clear()
        } else seen.add(total)
    }
    return result;
};
