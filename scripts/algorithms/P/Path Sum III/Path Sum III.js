// Runtime: 70 ms (Top 80.89%) | Memory: 47.60 MB (Top 75.77%)

var pathSum = function(root, sum, presums = { '0': 1 }, prev = 0) {
    if (!root) return 0;
    let curr = prev + root.val;
    presums[curr] = (presums[curr] || 0) + 1;
    let res = (presums[curr - sum] || 0) - !sum;
    res += pathSum(root.left, sum, presums, curr) + pathSum(root.right, sum, presums, curr);
    presums[curr]--;
    return res;
};
