// Runtime: 117 ms (Top 41.38%) | Memory: 44.1 MB (Top 58.62%)
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */

var longestSubsequence = function(s, k) {
    let count = 0;
    let j = s.length - 1; // starting from the last digit
    let i = 0; // binary number position
    let acc = 0;

    while(j >= 0){
        let positionNumber = Number(s[j]) * Math.pow(2, i);
        j--;
        i++;
        if(acc + positionNumber > k) continue;

        acc += positionNumber;
        count++;
    }

    return count;
};
