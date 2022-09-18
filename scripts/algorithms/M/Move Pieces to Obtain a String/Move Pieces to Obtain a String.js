// Runtime: 151 ms (Top 47.54%) | Memory: 47.4 MB (Top 60.66%)
/**
 * @param {string} start
 * @param {string} target
 * @return {boolean}
 */
var canChange = function(start, target) {
    let i = 0
    let j = 0
    const len = start.length

    while(i <= len && j <= len) {
        while(i < len && start[i] === '_') i++
        while(j < len && target[j] === '_') j++

        if(i === len && j === len) return true
        if(i === len || j === len) return false

        if(start[i] !== target[j]) return false
        if(start[i] === 'L' && j > i) return false
        if(start[i] === 'R' && j < i) return false
        i++
        j++
    }

    return false
};
