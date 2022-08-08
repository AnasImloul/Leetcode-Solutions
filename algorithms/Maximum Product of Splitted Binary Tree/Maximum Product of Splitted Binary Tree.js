var maxProduct = function(root) {
    const lefteRightSumMap = new Map();
    
    function getLeftRightSumMap(node) {
        if (node === null)
            return 0;

        let leftSum = getLeftRightSumMap(node.left);
        let rightSum = getLeftRightSumMap(node.right);
        
        lefteRightSumMap.set(node, {leftSum, rightSum});
        
        return leftSum + rightSum + node.val;
    }
    
    getLeftRightSumMap(root);
    
    let maxProduct = -Infinity;

    function getMaxProductDFS(node, parentSum) {
        if (node === null) return;
        
        const {leftSum, rightSum} = lefteRightSumMap.get(node);
        
        // cut left edge
        maxProduct = Math.max(maxProduct, leftSum * (parentSum + node.val + rightSum));
        
        // cut right edge
        maxProduct = Math.max(maxProduct, rightSum * (parentSum + node.val + leftSum));

        getMaxProductDFS(node.left, parentSum + node.val + rightSum);
        getMaxProductDFS(node.right, parentSum + node.val + leftSum);
    }
    
    getMaxProductDFS(root, 0);
    
    return maxProduct % (Math.pow(10, 9) + 7);
};
