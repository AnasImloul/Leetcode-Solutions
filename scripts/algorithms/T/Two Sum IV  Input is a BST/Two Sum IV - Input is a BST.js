// Runtime: 185 ms (Top 20.20%) | Memory: 51.8 MB (Top 62.64%)
var findTarget = function(root, k) {

    const set = new Set();

    const search = (root, k) => {
        if (!root) return false;
        if (set.has(k - root.val)) return true;
        set.add(root.val);
        return search(root.left, k) || search(root.right, k);
    }

    return search(root,k);
};