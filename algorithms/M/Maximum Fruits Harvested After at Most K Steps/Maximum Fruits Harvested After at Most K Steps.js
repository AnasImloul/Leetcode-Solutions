/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function(fruits, startPos, k) {
    
    let n = Math.max(fruits[fruits.length-1][0], startPos)+1;
    let numFruits = new Array(n).fill(0);
    let sums = new Array(n).fill(0);
    for(let obj of fruits) {
        let [pos, num] = obj;
        numFruits[pos] = num;
    }
    sums[startPos] = numFruits[startPos] ;
    for(let i = startPos+1; i < n && i <= startPos + k; i++) {
        sums[i] = sums[i-1] + numFruits[i];
    }
    for(let i = startPos-1; i >=0 && i >= startPos - k; i--) {
        sums[i] = sums[i+1] + numFruits[i];
    }
    //console.log(sums);
    let output = 0;
    for(let leftMoves = k; leftMoves >= 0; leftMoves--) {
        let rightMoves = Math.max(k - 2*leftMoves, 0);
        let leftPos = Math.max(0, startPos - leftMoves);
        let rightPos = Math.min(n-1, startPos + rightMoves);
        let count = sums[leftPos] + sums[rightPos] - sums[startPos];
        output = Math.max(output, count);
    }
    for(let rightMoves = k; rightMoves >= 0; rightMoves--) {
        let leftMoves = Math.max(k - 2*rightMoves, 0);
        let leftPos = Math.max(0, startPos - leftMoves);
        let rightPos = Math.min(n-1, startPos + rightMoves);
        let count = sums[leftPos] + sums[rightPos] - sums[startPos];
        output = Math.max(output, count);
    }
    return output;
};