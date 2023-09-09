// Runtime: 4176 ms (Top 50.0%) | Memory: 43.11 MB (Top 12.5%)

/**
 * @param {string} s1
 * @param {number} n1
 * @param {string} s2
 * @param {number} n2
 * @return {number}
 */
var getMaxRepetitions = function(s1, n1, s2, n2) {
    const len1 = s1.length;
    const len2 = s2.length; 
    let count1 = 0; // Number of times s2 can be formed from s1
    let count2 = 0; // Number of times str2 = [s2, count2] can be formed from str1 = [s1, count1]
    let i = 0; // Pointer for s1
    let j = 0; // Pointer for s2
    while (count1 < n1) {
        if (s1[i] === s2[j]) {
            j++;
            if (j === len2) {
                j = 0;
                count2++;
            }
        }
        i++;
        if (i === len1) {
            i = 0;
            count1++;
        }
    }
    return Math.floor(count2 / n2);
};