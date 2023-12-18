// Runtime: 55 ms (Top 53.46%) | Memory: 42.60 MB (Top 83.59%)

var checkTree = function(root) {
    return root.val === root.left.val + root.right.val;
};
