// Runtime: 330 ms (Top 57.14%) | Memory: 59.4 MB (Top 77.14%)
var isPossibleDivide = function(nums, k) {
    if(nums.length % k) {
        return false;
    }

    nums.sort((a, b) => a - b);

    let numberOfArrays = nums.length / k, index = 0, dp = Array(numberOfArrays).fill(null).map(() => []);

    dp[0].push(nums[0]);

    for(let i = 1; i < nums.length; i++) {
        if(nums[i] === nums[i - 1]) {
            if(index === numberOfArrays - 1) {
                return false;
            }
            index++;
        }
        else {
            index = 0;
            while(dp[index].length === k) {
                index++;
            }
        }
        if(dp[index].length && dp[index].at(-1) + 1 != nums[i]) {
            return false;
        }
        dp[index].push(nums[i])
    }

    return true;
};