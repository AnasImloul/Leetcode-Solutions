var maxDistance = function(position, m) {
    position = position.sort((a, b) => a - b);

    function canDistribute(n) {
        let count = 1;
        let dist = 0;
        
        for(let i = 1; i < position.length; i++) {
            dist += position[i] - position[i - 1];
            
            if (dist >= n) {
                count++;
                dist = 0;
            }
        }
        
        return count >= m;
    }
    
    let left = 1;
    let right = position[position.length - 1] - position[0];
    let ans;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (canDistribute(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
};
