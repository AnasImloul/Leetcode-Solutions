var nearestValidPoint = function(x, y, points) {
    let min = Infinity
    let idx = -1
    points.forEach(([a,b], i)=>{
        if(a===x || b===y){
            const dist = Math.abs(x-a) + Math.abs(y-b)
            if(dist<min){
                idx = i
                min = dist
            }
        }
    })
    return idx
};
