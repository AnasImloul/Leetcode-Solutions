// Runtime: 82 ms (Top 76.74%) | Memory: 43.8 MB (Top 83.72%)
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoMaxTree = function(root, val) {
    // get new node
    var node = new TreeNode(val);

    // no root
    if(!root) {
        return node;
    }

    // upward derivation if val larger then root
    if(val > root.val) {
        return node.left = root, node;
    }

    // downward derivation
    root.right = insertIntoMaxTree(root.right, val);

    // root construct
    return root;
};