var getSkyline = function(buildings) {
    
    let results = [];
    
    let points = [];
    
    for (let building of buildings) {
        points.push([building[0],building[2]])
        points.push([building[1],-building[2]])
    }
    
    let heights = [];
    
    points.sort((a,b)=>(b[1]-a[1]))
    points.sort((a,b)=>(a[0]-b[0]))
    
    for (let point of points) {
        if(point[1] >0) {
            heights.push(point[1])
        }
        else {
            heights.splice(heights.indexOf(-point[1]),1)
        }
        let curHeight = (heights.length == 0?0:Math.max(...heights))
        
        if(results.length == 0 || results[results.length-1][1] != curHeight) results.push([point[0], curHeight]);
    }
    
    
    return results;
};
