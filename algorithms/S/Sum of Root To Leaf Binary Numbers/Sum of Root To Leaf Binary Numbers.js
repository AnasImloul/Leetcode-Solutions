var sumRootToLeaf = function(root) {
    
    let sum = 0;
    
    const getSum = (root, currStr) => {
        if(!root) {
            return;
        }
        
        if(!root.left && !root.right) {
            sum = sum + parseInt(currStr + root.val, 2);
        }
        
        getSum(root.left, '' + currStr + root.val);
        getSum(root.right, '' + currStr + root.val);
    }
    
    getSum(root, '');
    
    return sum;
};
