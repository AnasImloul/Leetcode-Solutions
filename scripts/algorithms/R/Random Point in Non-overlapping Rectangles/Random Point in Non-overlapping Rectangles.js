/**
 /**
 * @param {number[][]} rects
 */
var Solution = function(rects) {
    this.rects = rects;
    this.map = {};
    this.sum = 0;
    // we put in the map the number of points that belong to each rect
    for(let i in rects) {
        const rect = rects[i];
        // the number of points can be picked in this rectangle
        this.sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        this.map[this.sum] = i;
    }
    this.keys = Object.keys(this.map);
};

/**
 * @return {number[]}
 */
Solution.prototype.pick = function() {
    // random point pick between [1, this.sum]
    const randomPointPick = Math.floor(Math.random() * this.sum) + 1;
    
    // we look for the randomPointPick in the keys of the map
    let pointInMap;
    // the keys exists in map
    if(this.map[randomPointPick]) pointInMap = randomPointPick;
    // the key is the first in the map (we do this check before doing binary search because its out of boundery)
    else if(randomPointPick < this.keys[0]) pointInMap = this.keys[0];
    let high = this.keys.length;
    let low = 1;
    // binary search to find the closest key that bigger than randomPointPick
    while(low <= high && !pointInMap) {
        const mid = Math.floor((low + (high-low)/2));
        if(randomPointPick > this.keys[mid-1] && randomPointPick < this.keys[mid]) {
            pointInMap = this.keys[mid];
            break;
        } else if (randomPointPick > this.keys[mid]){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    // we have the point, now we can get which rect belong to that point
    const pointInRects = this.map[pointInMap];
    const chosen = this.rects[pointInRects];
    const rightX = chosen[2];
    const leftX = chosen[0];
    const topY = chosen[3];
    const bottomY = chosen[1];
    const pickX = Math.floor(Math.random() * (rightX-leftX+1)) + leftX;
    const pickY = Math.floor(Math.random() * (topY-bottomY+1)) + bottomY;
    return [pickX, pickY]
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(rects)
 * var param_1 = obj.pick()
 */
