// Runtime: 99 ms (Top 68.02%) | Memory: 44.9 MB (Top 22.45%)

var sortedArrayToBST = function(nums) {
    if (nums.length === 0) return null;
    // array length - 1 divided by 2
    let mid = (nums.length - 1) >> 1;
    let node = new TreeNode(nums[mid]);
    node.left = sortedArrayToBST(nums.slice(0, mid));
    node.right = sortedArrayToBST(nums.slice(mid + 1));
    return node;
};