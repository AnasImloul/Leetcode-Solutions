// Runtime: 117 ms (Top 56.52%) | Memory: 45.2 MB (Top 69.57%)
var constructFromPrePost = function(preorder, postorder) {
    let preIndex = 0

    const dfs = (postArr) => {
        if (postArr.length === 0) return null

        const val = preorder[preIndex]
        const nextVal = preorder[++preIndex]
        const mid = postArr.indexOf(nextVal)

        const root = new TreeNode(val)
        root.left = dfs(postArr.slice(0, mid + 1))
        root.right = dfs(postArr.slice(mid + 1, postArr.indexOf(val)))

        return root
    }

    return dfs(postorder)
};