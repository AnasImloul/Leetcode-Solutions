// Runtime: 95 ms (Top 61.59%) | Memory: 47.40 MB (Top 79.47%)

/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var findThePrefixCommonArray = function(A, B) {
    let seen = new Set();
    let prefixCommonArr = [];
    let currentCount = 0;

    for (let i = 0; i < A.length; i++) {
        if (seen.has(A[i])) {
            currentCount += 1;
        }
        seen.add(A[i]);

        if (seen.has(B[i])) {
            currentCount +=1 ;
        }
        seen.add(B[i]);
        
        prefixCommonArr[i] = currentCount;
    }

    return prefixCommonArr;
};
