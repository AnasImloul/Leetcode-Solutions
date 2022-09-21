// Runtime: 104 ms (Top 17.42%) | Memory: 41.6 MB (Top 89.39%)
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
    if(rec1[0] >= rec2[2] || rec2[0] >= rec1[2] || rec1[1] >= rec2[3] || rec2[1] >= rec1[3]){
        return false
    }
    return true
};