// Runtime: 97 ms (Top 93.88%) | Memory: 51.4 MB (Top 81.78%)
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