// Runtime: 230 ms (Top 100.0%) | Memory: 56.70 MB (Top 50.0%)

var minSpaceWastedKResizing = function(nums, k) {
    var prefixSum = []; // prefix is index 1 based
    var rangeMax = []; // index 0 based
    var sum = 0;
    prefixSum[0] = 0; 
    for (var i = 0; i < nums.length; i++) {
        sum += nums[i];
        prefixSum[i + 1] = sum;
    }
    for (var i = 0; i < nums.length; i++) {
        var max = -Infinity;
        rangeMax[i] = [];
        for (var j = i; j < nums.length; j++) {
            max = Math.max(nums[j], max);
            rangeMax[i][j] = max;
        }
    }
    var f = []; // f[i][j] is resize i times to get minimun with index j - 1 to get minimum space.
    f[0] = [];
    for (var i = 0; i <= k; i++) {
        f[i] = [];
        f[i][0] = 0;
    }
    for (var j = 1; j <= nums.length; j++) {
        f[0][j] = rangeMax[0][j - 1] * j - prefixSum[j];
    }

    for (var i = 1; i <= k; i++) {
        for (var j = 1; j <= nums.length; j++) {
            f[i][j] = Infinity;
            for (var m = 1; m <= j; m++) {
                f[i][j] = Math.min(f[i][j], f[i - 1][m - 1] + rangeMax[m - 1][j - 1] * (j - m + 1) - (prefixSum[j] - prefixSum[m - 1]));
            }
        }
    }
    return f[k][nums.length];
};
