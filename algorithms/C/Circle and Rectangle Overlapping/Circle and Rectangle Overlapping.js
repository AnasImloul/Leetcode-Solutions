var checkOverlap = function(radius, xCenter, yCenter, x1, y1, x2, y2) {
    const closestX = clamp(xCenter, x1, x2);
    const closestY = clamp(yCenter, y1, y2);
    
    const dist = (xCenter - closestX)**2 + (yCenter - closestY)**2;
    
    return dist <= radius * radius ? true : false;
    
    
    function clamp(val, min, max) {
        if (val < min) return min;
        if (max < val) return max;
        return val;
    }
};
