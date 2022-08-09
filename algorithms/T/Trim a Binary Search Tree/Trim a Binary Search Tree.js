var trimBST = function(root, low, high) {
    if(!root) return null;
    const { val, left, right } = root;
    if(val < low) return trimBST(root.right, low, high);
    if(val > high) return trimBST(root.left, low, high);
    
    root.left = trimBST(root.left, low, high);
    root.right = trimBST(root.right, low, high);
    return root;
};
