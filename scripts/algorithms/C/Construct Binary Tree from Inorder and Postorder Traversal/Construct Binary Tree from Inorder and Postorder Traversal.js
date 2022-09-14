// Runtime: 92 ms (Top 87.91%) | Memory: 45.1 MB (Top 70.11%)
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    let postIndex = postorder.length - 1

    const dfs = (left, right) => {
        if (left > right) return null

        const val = postorder[postIndex--]
        const mid = inorder.findIndex(e => e === val)
        const root = new TreeNode(val)

        root.right = dfs(mid + 1, right)
        root.left = dfs(left, mid - 1)

        return root
    }

    return dfs(0, inorder.length - 1)
};