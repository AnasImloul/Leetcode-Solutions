// Runtime: 148 ms (Top 30.20%) | Memory: 47.4 MB (Top 67.11%)
var removeLeafNodes = function(root, target) {
    const parent = new TreeNode(-1, root, null);

    const traverse = (r = root, p = parent, child = -1) => {
        if(!r) return null;
        traverse(r.left, r, -1);
        traverse(r.right, r, 1);
        if(r.left == null && r.right == null && r.val == target) {
            if(child == -1) p.left = null;
            else p.right = null;
        }
    }
    traverse();
    return parent.left;
};