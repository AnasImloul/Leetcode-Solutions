// Runtime: 914 ms (Top 13.33%) | Memory: 98.8 MB (Top 66.67%)
/**
 * @param {number[][]} segments
 * @return {number[][]}
 */
var splitPainting = function(segments) {
    const arr = [];
    segments.forEach(([start, end, val])=>{
        arr.push([start, val]);
        arr.push([end, -val]);
    });
    arr.sort((i,j)=>i[0]-j[0]);

    const ans = [];
    let currVal = 0, prevTime;
    arr.forEach(([time, val])=>{
        if(prevTime !== undefined && currVal && prevTime !== time) ans.push([prevTime, time, currVal]);
        currVal += val;
        prevTime = time;
    })

    return ans;
};