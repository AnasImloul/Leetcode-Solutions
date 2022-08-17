var checkTree = function(root) {
    let value = root.left.val + root.right.val;
    value = value === root.val ? true : false;
    return value;
};
