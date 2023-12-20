// Runtime: 73 ms (Top 20.02%) | Memory: 47.50 MB (Top 17.03%)

var averageOfSubtree = function(root) {
    let result = 0;
    
    const traverse = node => {
        if (!node) return [0, 0];
        
        const [leftSum, leftCount] = traverse(node.left);
        const [rightSum, rightCount] = traverse(node.right);
        
        const currSum = node.val + leftSum + rightSum;
        const currCount = 1 + leftCount + rightCount;
        
        if (Math.floor(currSum / currCount) === node.val) result++;
        
        return [currSum, currCount];
    };
    
    traverse(root);
    return result;
};
