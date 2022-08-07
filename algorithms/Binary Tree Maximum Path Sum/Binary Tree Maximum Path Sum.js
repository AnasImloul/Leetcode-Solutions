var maxPathSum = function(root) {
    let res = -Infinity;
    function solve(root){
        if(!root){
            return 0;
        }
        
        let left = solve(root.left);
        let right = solve(root.right);
        //ignore the values with negative sum
        let leftVal = Math.max(left, 0);
        let rightVal = Math.max(right,0);
        
        let localMax = leftVal + rightVal + root.val;
        res = Math.max(localMax,res);
        return Math.max(leftVal, rightVal) + root.val;
        
    }
    solve(root);
    return res;
    
};
