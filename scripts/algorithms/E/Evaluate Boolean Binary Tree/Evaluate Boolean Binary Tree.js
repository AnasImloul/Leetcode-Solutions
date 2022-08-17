/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var evaluateTree = function(root) {
  return root.val === 3 ? evaluateTree(root.left) && evaluateTree(root.right) :
         root.val === 2 ? evaluateTree(root.left) || evaluateTree(root.right) :
         root.val;
};
