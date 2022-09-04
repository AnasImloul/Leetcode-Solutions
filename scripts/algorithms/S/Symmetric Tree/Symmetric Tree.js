// Runtime: 104 ms (Top 51.21%) | Memory: 44.5 MB (Top 57.00%)
var isSymmetric = function(root) {
    return helper(root.left, root.right);

    function helper(left, right){
        if(!left && !right) return true;
        if((!left && right) || (left && !right) || (left.val !== right.val)) return false;
        return helper(left.left, right.right) && helper(left.right, right.left)
    }
};
