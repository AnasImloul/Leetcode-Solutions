// Runtime: 154 ms (Top 50.0%) | Memory: 48.85 MB (Top 59.5%)

/**
 * @param {string} s
 * @return {number}
 */
var minFlips = function(s) {
    let length = s.length-1
    let flipMap = {
        '1': '0',
        '0': '1'
    }
    s = s + s
    let alt1 = '1'
    let alt2 = '0'
    let left = 0
    let right = 0
    let diff1 = 0
    let diff2 = 0
    let min = Infinity

    while (right < s.length) {
        if (right > 0) {
            alt1 = flipMap[alt1]
            alt2 = flipMap[alt2]
        }

        let current = s[right]
        if (current !== alt1) diff1++
        if (current !== alt2) diff2++
        if (right-left === length) {
            min = Math.min(diff1, diff2, min)
            if ((length+1)%2 === 0) {
                if (s[left] !== flipMap[alt1]) diff1--
                if (s[left] !== flipMap[alt2]) diff2--
            } else {
                if (s[left] !== alt1) diff1--
                if (s[left] !== alt2) diff2--
            }
            left++
        }
        right++
    }
    return min
};