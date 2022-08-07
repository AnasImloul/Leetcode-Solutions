var maxDepth = function(root) {
    if(root == null) return 0
    
    let leftDepth = maxDepth(root.left)
    let rightDepth = maxDepth(root.right)
    
    let ans = Math.max(leftDepth,rightDepth) + 1
    
    return ans
};
