// Runtime: 88 ms (Top 52.38%) | Memory: 42.9 MB (Top 9.52%)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var pruneTree = function(root) {
    let rec = function(node){
        if(node==null) return null;
        if(node.val===0 && node.left == null && node.right == null){
            return null
        }
        node.left = rec(node.left);
        node.right = rec(node.right);
        // For updated tree structure if threre are leaf nodes with zero value present, if yes then return null otherewise return node itself.
        if(node.val===0 && node.left == null && node.right == null){
            return null
        }
        return node;
    }
    rec (root);
    if(root.val == 0 && root.left == null && root.right == null) return null

    return root;
};