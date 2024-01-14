// Runtime: 60 ms (Top 81.44%) | Memory: 47.50 MB (Top 87.63%)

var trimBST = function(root, low, high) {
    if (!root) return null;
    if (root.val < low) root = trimBST(root.right, low, high);
    else if (root.val > high) root = trimBST(root.left, low, high);
    else {
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
    }
    return root;
};
