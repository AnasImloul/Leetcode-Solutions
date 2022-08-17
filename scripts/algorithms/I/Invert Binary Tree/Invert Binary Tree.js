var invertTree = function(root) {
  if (!root) return root;
    [root.left, root.right] = [root.right, root.left];
    invertTree(root.right)
    invertTree(root.left)
     return root
};

