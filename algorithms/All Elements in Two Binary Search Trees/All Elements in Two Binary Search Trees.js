var getAllElements = function(root1, root2) {
    const ans = [];
    const traverse = (r) => {
        if(!r) return;
        traverse(r.left);
        ans.push(r.val);
        traverse(r.right);
    }
    traverse(root1);
    traverse(root2);
    return ans.sort((a, b) => a - b);
};
