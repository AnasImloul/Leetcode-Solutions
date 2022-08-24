// Runtime: 112 ms (Top 63.93%) | Memory: 45.9 MB (Top 77.87%)
/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    let count = 0;
    for(let i=0; i<strs[0].length; i++){
        for(let j=0; j<strs.length-1; j++){
            if(strs[j].charAt(i) > strs[j+1].charAt(i)){
                count++;
                break;
            }
        }
    }
    return count;
};