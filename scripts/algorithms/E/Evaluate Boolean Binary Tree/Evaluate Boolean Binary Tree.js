// Runtime: 129 ms (Top 23.56%) | Memory: 48.4 MB (Top 85.63%)
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var evaluateTree = function(root) {
  return root.val === 3 ? evaluateTree(root.left) && evaluateTree(root.right) :
         root.val === 2 ? evaluateTree(root.left) || evaluateTree(root.right) :
         root.val;
};