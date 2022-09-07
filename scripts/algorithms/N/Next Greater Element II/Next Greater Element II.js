// Runtime: 218 ms (Top 26.53%) | Memory: 48.7 MB (Top 35.44%)
var nextGreaterElements = function(nums) {
    const len = nums.length;
    const ans = new Array(len).fill(-1);
    const stack = [];
    for(let i = 0; i < len; i++) {
        if(i == 0) stack.push([i, nums[i]]);
        else {
            while(stack.length && stack.at(-1)[1] < nums[i]) {
                ans[stack.pop()[0]] = nums[i];
            }
            stack.push([i, nums[i]]);
        }
    }
    for(let num of nums) {
        while(stack.length && stack.at(-1)[1] < num) {
            ans[stack.pop()[0]] = num;
        }
    }
    return ans;
};