// Runtime: 88 ms (Top 88.89%) | Memory: 52.30 MB (Top 77.78%)

var minOperations = function(nums1, nums2) {
    /*
    Two impossible cases:
    min1...max1 ... min2...max2 -> we can't make them equal
    min2...max2 ... min1...max1 -> we can't make them equal
    */
    let min1 = nums1.length * 1;
    let max1 = nums1.length * 6;
    let min2 = nums2.length * 1;
    let max2 = nums2.length * 6;
    if (min2 > max1 || min1 > max2) {
        return -1;
    }
    let sum1 = nums1.reduce((acc,cur) => acc + cur);
    let sum2 = nums2.reduce((acc,cur) => acc + cur);
    if (sum1 === sum2) return 0;
    if (sum1 < sum2) {
        return helper(nums1, nums2, sum1, sum2);
    } else {
        return helper(nums2, nums1, sum2, sum1);
    }
    // T.C: O(M + N), M = # of nums1, N = # of nums2
    // S.C: O(1)
};

// Condition: sum of A < sum of B
// the idea is to add the maximum possible value to sumA and
// subtract the maximum possible value from sumB so that
// we make sumA >= sumB as soon as possible
function helper(A, B, sumA, sumB) {
    let freqA = new Array(7).fill(0);
    let freqB = new Array(7).fill(0);
    for (let i = 0; i < A.length; i++) {
        freqA[A[i]]++;
    }
    for (let i = 0; i < B.length; i++) {
        freqB[B[i]]++;
    }
    let count = 0;
    for (let i = 1; i <= 6; i++) {
        // increase sumA
        while (freqA[i] > 0 && sumA < sumB) {
            sumA += 6-i;
            freqA[i]--;
            count++;
        }
        let j = 7-i;
        // decrease sumB
        while (freqB[j] > 0 && sumA < sumB) {
            sumB -= j-1;
            freqB[j]--;
            count++;
        }
        if (sumA >= sumB) break;
    }
    return count;
}
