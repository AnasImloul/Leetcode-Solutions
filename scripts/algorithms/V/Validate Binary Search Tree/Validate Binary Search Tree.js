// Runtime: 118 ms (Top 5.02%) | Memory: 46.60 MB (Top 30.57%)

var isValidBST = function(root) {
    
    return validate(root, -Infinity, Infinity);
};


var validate = function(node, lower,upper){
    
    if ( node == null ){
        
        // empty node or empty tree
        return true;
    }
    
    if( (lower < node.val) && ( node.val < upper ) ){
        
        // check if all tree nodes follow BST rule
        return validate( node.left, lower, node.val) && validate( node.right, node.val, upper);
    }else{
        
        // early reject when we find violation
        return false;
    }
    
}
