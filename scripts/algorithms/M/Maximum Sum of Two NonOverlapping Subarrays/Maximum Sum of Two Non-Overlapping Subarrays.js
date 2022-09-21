// Runtime: 95 ms (Top 65.79%) | Memory: 43.9 MB (Top 60.53%)
var maxSumTwoNoOverlap = function(nums, firstLen, secondLen) {
    function helper(arr, x, y)
    {
        const n = arr.length;
        let sum = 0;
        const dp1 = []; // store left x sum
        const dp2 = []; // store right y sum

        for(let i = 0; i<n; i++)
        {
            if(i<x) {
                sum += arr[i];
                dp1[i] = sum;
            }
            else {
                sum += arr[i] - arr[i-x];
                dp1[i] = Math.max(dp1[i-1], sum);
            }
        }
        sum = 0;
        for(let i = n-1; i>=0; i--)
        {
            if(i>=n-y)
            {
                sum += arr[i];
                dp2[i] = sum;
            }
            else
            {
                sum += arr[i] - arr[i+y];
                dp2[i] = Math.max(dp2[i+1], sum);
            }
        }
        let max = -Infinity;
        for(let i = x-1; i< n-y; i++)
        {
            max = Math.max(max, dp1[i] + dp2[i+1]);
        }
        return max;
    }
    return Math.max(helper(nums, firstLen, secondLen),
                   helper(nums, secondLen, firstLen));
};