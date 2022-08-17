var deleteAndEarn = function(nums) {
    let maxNumber = 0;
    
    const cache = {};
    const points = {};

    function maxPoints(num) {
        if (num === 0) {
            return 0;
        }
        
        if (num === 1) {
            return points[1] || 0;
        }
        
        if (cache[num] !== undefined) {
            return cache[num];
        }
        
        const gain = points[num] || 0;
        return cache[num] = Math.max(maxPoints(num - 1), maxPoints(num - 2) + gain);
    }
    
    for (let num of nums) {
        points[num] = (points[num] || 0) + num;
        maxNumber = Math.max(maxNumber, num);
    }

    return maxPoints(maxNumber);
};
