// Runtime: 86 ms (Top 54.59%) | Memory: 41.8 MB (Top 88.92%)
var inorderTraversal = function(root) {
    let result = [];
    function traverse(node) {
        if(!node) {
            return;
        }
        traverse(node.left);
        result.push(node.val);
        traverse(node.right);
    }
    traverse(root);
    return result;
};