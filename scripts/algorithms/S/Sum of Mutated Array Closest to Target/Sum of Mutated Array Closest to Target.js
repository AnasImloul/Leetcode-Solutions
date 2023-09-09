// Runtime: 70 ms (Top 33.3%) | Memory: 44.73 MB (Top 22.2%)

/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var findBestValue = function(arr, target) {
    const sortedArr = [...arr].sort(function (a, b) {  return a - b;  });
    var lowestValue = Math.min(sortedArr[arr.length-1], Math.floor(target/arr.length));
    var higestValue = Math.min(sortedArr[arr.length-1], target);
    var value, deltaLeft, deltaRight;
    
    while (true) {
        candidateRight = Math.ceil((lowestValue + higestValue)/2)
        candidateLeft = candidateRight - 1
        deltaLeft = calculateDeltaForCandidate(sortedArr, target, candidateLeft)
        if (deltaLeft == 0) {
            return candidateLeft
        }
        deltaRight = calculateDeltaForCandidate(sortedArr, target, candidateRight)
        if (deltaRight == 0) {
            return candidateRight
        }
        if (deltaRight == 0) {
            return candidateRight
        }
        if (candidateRight == higestValue) {
            return deltaLeft <= deltaRight ? candidateLeft : candidateRight;
        }
        if (deltaLeft <= deltaRight) {
            higestValue = candidateLeft
        } else {
            lowestValue = candidateRight
        }
    }
};

var calculateDeltaForCandidate = function(sArr, target, candidate) {
    var sum
    //find idx lover then candidate
    for (var i=0; i < sArr.length; i++) {
        if (sArr[i] >= candidate) {
            sum = sArr.slice(0, i).reduce((partialSum, a) => partialSum + a, 0) + (sArr.length - i) * candidate;
            return Math.abs(sum - target)
        };
    }
    return NaN
};
