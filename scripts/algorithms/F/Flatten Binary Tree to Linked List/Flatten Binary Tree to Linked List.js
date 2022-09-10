// Runtime: 134 ms (Top 14.04%) | Memory: 45 MB (Top 18.98%)
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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    const dfs = (node) => {
        if (!node) return

        if (!node.left && !node.right) return node

        const leftNode = node.left
        const rightNode = node.right

        const leftTree = dfs(leftNode)
        const rightTree = dfs(rightNode)

        if (leftTree) leftTree.right = rightNode

        node.left = null
        node.right = leftNode || rightNode

        return rightTree || leftTree
    }

    dfs(root)
    return root
};