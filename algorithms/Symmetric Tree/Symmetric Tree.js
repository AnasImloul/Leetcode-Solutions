var isSymmetric = function(root) {
    return helper(root.left, root.right);
    
    function helper(left, right){
        if(!left && !right) return true;
        if((!left && right) || (left && !right) || (left.val !== right.val)) return false;
        return helper(left.left, right.right) && helper(left.right, right.left)
    }
};


