// Runtime: 315 ms (Top 76.6%) | Memory: 102.50 MB (Top 95.74%)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthLargestLevelSum = function(root, k) {
    const data = []
    const dfs = (node,level)=>{
        if(node == null)return;
        data[level]?data[level] += node.val:data[level] =  node.val
        dfs(node.left,level+1)
        dfs(node.right,level+1)
    }
    dfs(root,0);
    if(k>data.length)return -1;
    data.sort((a,b) => b-a)
    return data[k-1]
};
