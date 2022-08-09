var maxWidthOfVerticalArea = function(points) {
    let ans = 0;
    points = points.map(item => item[0]).sort((a, b) => a - b);
    
    for(let i = 1; i < points.length; i++){
        
        ans = Math.max(ans, points[i] - points[i-1]);
    }
        
    return ans;
};
