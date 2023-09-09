// Runtime: 90 ms (Top 100.0%) | Memory: 44.29 MB (Top 89.4%)

var countLatticePoints = function(circles) {
    let minX=minY=Infinity, maxX=maxY=-Infinity;
    for(let i=0; i<circles.length; i++){
        minX=Math.min(minX, circles[i][0]-circles[i][2]); maxX=Math.max(maxX, circles[i][0]+circles[i][2]);
        minY=Math.min(minY, circles[i][1]-circles[i][2]); maxY=Math.max(maxY, circles[i][1]+circles[i][2]);
    }
	
    let count=0;
    for(let i=minX; i<=maxX; i++){
        for(let j=minY; j<=maxY; j++){
            let find=false;
            for(let k=0; k<circles.length; k++){
                if(((i-circles[k][0])**2+(j-circles[k][1])**2)<=circles[k][2]**2){
                    find=true; break;
                }
            }
            if(find){count++};
        }
    }
    return count;
};