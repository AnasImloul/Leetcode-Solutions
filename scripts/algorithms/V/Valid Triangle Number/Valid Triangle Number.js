// Runtime: 103 ms (Top 39.24%) | Memory: 50.90 MB (Top 13.92%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) {
    nums.sort((a,b) => a-b);
    let result = 0, n = nums.length, i, j, k;
    for(i = 0; i<n ; i++) {
        for(j = i+1, k = j+1; j<(n - 1) && k<=n;) {
            if(k == n || nums[i]+nums[j] <= nums[k]){
                if(k > (j+1))
                    result += k - j - 1;
                j++;
            }else k++;
        }
    }
    return result;
};
