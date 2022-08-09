/** https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var longestZigZag = function(root) {
  this.out = 0;

  // Recursive left and right node and find the largest height
  let left = dfs(root.left, false) + 1;
  let right = dfs(root.right, true) + 1;
  this.out = Math.max(this.out, Math.max(left, right));
  
  return this.out;
};

var dfs = function(node, isLeft) {
  // Node is null, we return -1 because the caller will add 1, so result in 0 (no node visited)
  if (node == null) {
    return -1;
  }
  
  // No left or right node, we return 0 because the caller will add 1, so result in 1 (visited 1 node - this one)
  if (node.left == null && node.right == null) {
    return 0;
  }
  
  // Recursive to see which one is higher, zigzag to left or zigzag to right
  let left = dfs(node.left, false) + 1;
  let right = dfs(node.right, true) + 1;
  this.out = Math.max(this.out, Math.max(left, right));
  
  return isLeft === true ? left : right;
};
