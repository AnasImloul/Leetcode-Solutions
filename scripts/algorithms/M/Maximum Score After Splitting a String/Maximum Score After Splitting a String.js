// Runtime: 45 ms (Top 96.83%) | Memory: 48.50 MB (Top 8.24%)

/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
    const length = s.length;
        let ones = 0;
        let tmpScore = s[0] === '0' ? 1 : 0;
        let score = tmpScore;
        
        for (let i = 1; i < length - 1; i++) {
            if (s[i] === '0') {
                tmpScore += 1;
            } else {
                ones += 1;
                tmpScore -= 1;
            }

            if (tmpScore > score) {
                score = tmpScore;
            }
        }
        
        ones += s[length - 1] === '1' ? 1 : 0;

        return ones + score;
};
