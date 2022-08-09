 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    const leftScores = []
    const rightScores = []
    let score = 0
    for (let i = 0; i < s.length-1; i++) {
        if (s[i] === '0') 
            score++
        leftScores.push(score)
    }
    score = 0
    for (let i = s.length-1; i > 0; i--) {
        if (s[i] === '1')
            score++
        rightScores.unshift(score)
    }
    
    const scores = leftScores.map((val, idx) => val + rightScores[idx])
    return Math.max(...scores)
};
