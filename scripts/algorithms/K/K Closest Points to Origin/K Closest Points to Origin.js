/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function(points, k) {
    let res = [];
    let hashMap = new Map();
    for(let i = 0; i < points.length; i++) {
		//store the distance and the index of the points in a map
        const dis = calcDis(points[i]);
        hashMap.set(i, dis);
    }
	//sort the map by its distance to the origin
    const hashMapNew = new Map([...hashMap].sort((a,b) => a[1] - b[1]));
	//use the index sorted by distance to get the result
    let i = 0;
    for(const x of hashMapNew.keys()) {
		//do it k times
        if(i === k) break;
        res.push(points[x]);
        i++;
    }
    return res;
};
var calcDis = (b) => {
    return Math.sqrt( Math.pow(b[0], 2) + Math.pow(b[1], 2) );
}
