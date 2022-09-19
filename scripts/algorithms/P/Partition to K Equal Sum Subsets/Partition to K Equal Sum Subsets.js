// Runtime: 74 ms (Top 96.55%) | Memory: 44.5 MB (Top 25.86%)
var canPartitionKSubsets = function(nums, k) {
    const sum = nums.reduce((sum, num) => sum + num);
    const divide = sum / k;
    if (!Number.isInteger(divide)) return false;
    const subsets = Array(k).fill(0);
    const dfs = (index = 0) => {
        if (index >= nums.length) return true;
        const visited = new Set();
        const num = nums[index];

        for (let sub = 0; sub < k; sub++) {
            const subset = subsets[sub];
            if (visited.has(subset) || subset + num > divide) continue;

            visited.add(subset);
            subsets[sub] += num;
            if (dfs(index + 1)) return true;
            subsets[sub] -= num;
        }
        return false;
    };

    nums.sort((a, b) => b - a);
    return dfs();
};