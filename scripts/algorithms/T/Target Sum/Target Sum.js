var findTargetSumWays = function(nums, target) {
    const memo = new Map()
    return backtrack(0, 0)
    
    function backtrack(i, cur){
        const key = `${i} ${cur}`
        if(i == nums.length) return cur == target ? 1 : 0
        if(!memo.has(key)) memo.set(key, backtrack(i + 1, -nums[i] + cur) + backtrack(i + 1, nums[i] + cur))
        return memo.get(key)
    }
};
