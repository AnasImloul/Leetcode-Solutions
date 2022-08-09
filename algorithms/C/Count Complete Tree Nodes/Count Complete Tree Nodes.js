var countNodes = function(root) {
    return root === null ? 0 : countNodes(root.left) + countNodes(root.right) + 1;
}
