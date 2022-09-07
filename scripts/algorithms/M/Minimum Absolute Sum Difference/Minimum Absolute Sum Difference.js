// Runtime: 253 ms (Top 81.48%) | Memory: 57.3 MB (Top 51.85%)
var minAbsoluteSumDiff = function(nums1, nums2) {
    const MOD = 1e9 + 7;
    const n = nums1.length;

    const origDiffs = [];
    let diffSum = 0;

    for (let i = 0; i < n; i++) {
        const num1 = nums1[i];
        const num2 = nums2[i];

        const currDiff = Math.abs(num1 - num2);

        origDiffs[i] = currDiff;
        diffSum += currDiff;
    }

    nums1.sort((a, b) => a - b);

    let minDiffSum = diffSum;

    for (let i = 0; i < n; i++) {
        const origDiff = origDiffs[i];

        const num2 = nums2[i];

        let left = 0;
        let right = n - 1;

        let bestDiff = origDiff;

        while (left <= right) {
            const mid = (left + right) >> 1;
            const num1 = nums1[mid];

            const candDiff = num1 - num2;

            if (Math.abs(candDiff) < bestDiff) {
                bestDiff = Math.abs(candDiff);
                if (bestDiff === 0) break;
            }

            if (candDiff < 0) left = mid + 1;
            else right = mid - 1;
        }

        const replacedDiffSum = (diffSum - origDiff) + bestDiff;

        minDiffSum = Math.min(minDiffSum, replacedDiffSum);
    }

    return minDiffSum % MOD;
};