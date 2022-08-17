var getSumAbsoluteDifferences = function(nums) {
    const N = nums.length;
    const ans = new Array(N);
    ans[0] = nums.reduce((a, b) => a + b, 0) - (N * nums[0]);
    for (let i = 1; i < N; i++)
        ans[i] = ans[i - 1] + (nums[i] - nums[i - 1]) * i - (nums[i] - nums[i - 1]) * (N - i); 
    return ans;
};
