var sortedArrayToBST = function(nums) {
    if (nums.length === 0) return null;
    // array length - 1 divided by 2
    let mid = (nums.length - 1) >> 1;
    let node = new TreeNode(nums[mid]);
    node.left = sortedArrayToBST(nums.slice(0, mid));
    node.right = sortedArrayToBST(nums.slice(mid + 1));
    return node;
};
