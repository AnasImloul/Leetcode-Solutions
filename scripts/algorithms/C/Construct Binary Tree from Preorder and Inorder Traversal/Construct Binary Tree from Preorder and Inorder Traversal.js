// Runtime: 121 ms (Top 79.59%) | Memory: 44.5 MB (Top 97.46%)
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    let idx = 0;
    function create(inorderStart, inorderEnd) {
        if (idx === preorder.length || inorderStart > inorderEnd) {
            return null;
        }
        const root = new TreeNode(preorder[idx]);
        const mid = inorder.indexOf(preorder[idx]);
        idx++;
        root.left = create(inorderStart, mid -1);
        root.right = create(mid + 1, inorderEnd);
        return root;
    }

    return create(0, inorder.length -1);
};