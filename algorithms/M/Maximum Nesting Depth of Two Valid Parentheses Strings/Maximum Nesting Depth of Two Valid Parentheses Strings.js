/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
    let arr = []
    for(let i=0; i<seq.length; i++){
        arr.push(seq[i] == "(" ? i & 1 : 1-i & 1)
    }
    return arr
};
