/**
 * @param {number[][]} items1
 * @param {number[][]} items2
 * @return {number[][]}
 */
var mergeSimilarItems = function(items1, items2) {
    let map = new Map();
    items1.reduce((map,curr)=>map.set(curr[0],map.get(curr[0])+curr[1]||curr[1]),map);
    items2.reduce((map,curr)=>map.set(curr[0],map.get(curr[0])+curr[1]||curr[1]),map);
    
    return [...map].sort((a,b)=>{
        return a[0] - b[0];
    })
};