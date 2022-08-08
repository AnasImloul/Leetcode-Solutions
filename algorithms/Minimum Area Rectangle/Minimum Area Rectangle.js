var minAreaRect = function(points) {
    const mapOfPoints = new Map();
    let minArea = Infinity;
    for(const [x,y] of points) {
        let keyString = `${x}:${y}`
        mapOfPoints.set(keyString, [x, y]);
    }
    for(const [xLeftBottom, yLeftBottom] of points) {
        for(const [xRightTop, yRightTop] of points) {
            if(!foundDiagonal(xLeftBottom, yLeftBottom, xRightTop, yRightTop)) continue;
            let leftTopCorner = `${xLeftBottom}:${yRightTop}`;
            let rightBottomCorner = `${xRightTop}:${yLeftBottom}`;
            
            if(mapOfPoints.has(leftTopCorner) && mapOfPoints.has(rightBottomCorner)) {
                const x2 = mapOfPoints.get(rightBottomCorner)[0];
                const x1 = xLeftBottom;
                const y1 = yLeftBottom;
                const y2 =  mapOfPoints.get(leftTopCorner)[1]
                const area = calculateArea(x1, x2, y1, y2);
                
                minArea = Math.min(minArea,area);
            }
        }
        
    }
    return minArea === Infinity ? 0 : minArea;
};


function calculateArea(x1, x2, y1, y2) {
    return ((x2-x1) * (y2-y1))
}

function foundDiagonal(xLeftBottom, yLeftBottom, xRightTop, yRightTop) {
    return (xRightTop > xLeftBottom && yRightTop > yLeftBottom);
}
