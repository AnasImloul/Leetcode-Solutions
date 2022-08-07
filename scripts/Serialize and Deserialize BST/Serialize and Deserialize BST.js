/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    if(!root) return "";
    let result = "";
    function DFS(root) {
        result = result ? result + ',' + root.val : result + root.val;
        if(root.left) {
            DFS(root.left);
        }
        if(root.right) {
            DFS(root.right);
        }
    }
    DFS(root);
    return result;
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    
    if(data === '') return null;
    preorder = data.split(',');
    let i = 0;
    function constructTree(lower, upper) {
        if(i === preorder.length) return null;
        if(Number(preorder[i]) > upper) return null;
        if(Number(preorder[i]) < lower) return null;

        let root = new TreeNode(preorder[i]);
        i++;
        root.left = constructTree(lower, root.val);
        root.right = constructTree(root.val, upper);
        return root;
    }
    return constructTree(-Infinity, Infinity);
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */