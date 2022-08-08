/**
 * @param {TreeNode} root
 * @return {string[][]}
 */
var printTree = function(root) {
	// find the height of the tree
    const m = getHeight(root)
    const height = m - 1
    const n = 2**(height+1)-1
    // create an empty m by n matrix    
    const ans = []
    for (let i = 0; i<m; i++) {
        ans.push(Array(n).fill(""))
    }
    // insert the root
    ans[0][(n-1)/2] = root.val.toString()
	// insert the rest of the nodes
    format(root,0,(n-1)/2,ans,height)
    return ans
};

function getHeight(node) {
    if (!node) return 0
    const leftHeight = getHeight(node.left)+1
    const rightHeight = getHeight(node.right)+1
    return Math.max(leftHeight,rightHeight) // take the subtree with bigger height
}

function format(node,r,c,ans,height) {
    const offset = 2**(height-r-1) // calculate the common offset
    if (node.left) {
        ans[r+1][c-offset] = node.left.val.toString()
        format(node.left,r+1,c-offset,ans,height) // recurse left node
    }
    if (node.right) {
        ans[r+1][c+offset] = node.right.val.toString()
        format(node.right,r+1,c+offset,ans,height) // recurse right node
    }
}
