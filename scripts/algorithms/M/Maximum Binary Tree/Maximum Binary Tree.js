// Runtime: 81 ms (Top 79.6%) | Memory: 49.10 MB (Top 75.12%)

var constructMaximumBinaryTree = function(nums) {
    max = Math.max(...nums)
    var index = nums.indexOf(max)
    var tree = new TreeNode(max)
    if(index !==0) tree.left = constructMaximumBinaryTree(nums.slice(0,index));
    if(index !==nums.length-1) tree.right=constructMaximumBinaryTree(nums.slice(index+1));
    return tree
}
