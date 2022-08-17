/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaFreeRect = function(points) {
    let len = points.length;
    
    if (len < 4) return 0;
    
    // Helper function to calculate distance
    // between two points, optionally return 
    // without sqrt if want to use as key
    const getDistance = (a, b, isKey = false) => {
        let [xa, ya] = a;
        let [xb, yb] = b;
        
        const distance = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
        return isKey ? distance : Math.sqrt(distance);
    }
    
    let map = new Map();
    
    // let's loop over all points and find all possible
    // diagonals and calc - dis with midpoints and 
    // save as key with co-ordinates as values
    for (let i = 0; i < len; i += 1) {
        for (let j = i + 1; j < len; j += 1) {
            let disKey = getDistance(points[i], points[j], true);
            let [xa, ya] = points[i];
            let [xb, yb] = points[j];
            
            let x = (xa + xb) / 2;
            let y = (ya + yb) / 2;
            
            let key = `${disKey}-${x}-${y}`;
            
            let list = [];
            
            if (!map.has(key)) {
                map.set(key, list)
            } else list = map.get(key);
            
            list.push([i, j]);
            
            map.set(key, list);
        }
    }
    
    // console.log(map);
    let res = Number.MAX_VALUE;
    
    // loop over map of keys above and
    // only iterate through the list where at least 
    // 2 set of co-ordinates have been found above
    map.forEach((list, key) => {
        if (list.length > 1) {
            for (let i = 0; i < list.length; i += 1) {
                for (let j = i + 1; j < list.length; j += 1) {
                    let p1 = list[i][0];
                    let p2 = list[j][0];
                    let p3 = list[j][1];
                    
                    let l = getDistance(points[p1], points[p2]);
                    let b = getDistance(points[p1], points[p3]);
                    res = Math.min(res, l * b);
                }
            }
        }
    })
    
    return res === Number.MAX_VALUE ? 0 : res;
    
};
