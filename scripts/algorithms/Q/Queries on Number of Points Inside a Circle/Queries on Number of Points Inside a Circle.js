var countPoints = function(points, queries) {
    const getDistance = (x1,y1,x2,y2) => {
        return Math.sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
    }
    
    let output = [];
    
    queries.forEach(([a,b,r]) => {
        let count = 0;
        points.forEach(([x,y]) => {
            if(getDistance(a,b,x,y) <= r) count += 1;
        });
        output.push(count);
    });
 
    return output;
};
