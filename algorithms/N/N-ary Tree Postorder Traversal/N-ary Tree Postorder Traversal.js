var postorder = function(root) {
    const res = [];
    function post(node) {
        if (!node) return;
        for (let child of node.children) {
            post(child);
        }
        res.push(node.val);
    }
    post(root);
    return res;
};
