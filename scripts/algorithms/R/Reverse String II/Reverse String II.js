// Runtime: 117 ms (Top 23.03%) | Memory: 44.8 MB (Top 54.82%)

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    const sArr = s.split('');

    let start = 0;
    let end = k - 1;

    const swapBlock = (start, end) => {
        while (start < end) {
            [sArr[start], sArr[end]] = [sArr[end], sArr[start]];

            start++;
            end--;
        }
    };

    while (start < end) {
        swapBlock(start, end);

        start = start + (k * 2);
        end = sArr[start + (k-1)] ? start + (k-1) : s.length - 1;
    }

    return sArr.join('');
};