// Runtime: 97 ms (Top 56.76%) | Memory: 44.4 MB (Top 35.14%)
var left, right, val;
var btreeGameWinningMove = function(root, n, x) {
    function count(node) {
        if (node == null)
            return 0;
        var l = count(node.left);
        var r = count(node.right);
        if (node.val == val) {
            left = l;
            right = r;
        }
        return l + r + 1;
    }
    val = x;
    count(root);
    return Math.max(n - left - right - 1, Math.max(left, right)) > n / 2;
};