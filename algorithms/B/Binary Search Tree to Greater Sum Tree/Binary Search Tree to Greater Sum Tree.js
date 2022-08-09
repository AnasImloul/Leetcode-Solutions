var bstToGst = function(root) {
    let sum = 0;
    const traverse = (r = root) => {
        if(!r) return null;
        traverse(r.right);
        let temp = r.val;
        r.val += sum;
        sum += temp;
        traverse(r.left);
    }
    traverse();
    return root;
};
