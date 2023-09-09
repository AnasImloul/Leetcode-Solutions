// Runtime: 69 ms (Top 97.8%) | Memory: 50.68 MB (Top 26.8%)

;/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    // Using Preorder traversal to create a string of BST
    // Preorder works in following way
    // root -> left -> right
    let preorder = [];
    
    function dfs(node) {
        if (node === null) return;
        // Get root value
        preorder.push(node.val);

        // Get All the Left values
        dfs(node.left);

        // Get all the right values
        dfs(node.right);
    }

    // call it with root
    dfs(root)

    // Turn into string and return it
    return preorder.join(',')
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (data === "") return null;

    // Get numbers array from a string
    const preorder = data.split(',').map(Number);

    // using -Infinity and +Infinity as placeholder check
    function recur(lower = -Infinity, upper = Infinity) {
        // This condition useful for when we are filling left side of tree it'll avoid all the values greater then then its upper value by putting null init.
        if (preorder[0] < lower || preorder[0] > upper) return null;

        // If preorder become empty
        if (preorder.length === 0) return null;

        // Create a root node [shift method will change the original array]
        const root = new TreeNode(preorder.shift());

        // Here for left side of tree, we are using current root node's value as 'upper bound' (so higher values ignored).
        root.left = recur(lower, root.val);

        // Same as above for right side we are using root node's values as 'lower bound' (so lower values ignored);
        root.right = recur(root.val, upper);

        return root;
    }

    // Final root will be out BST
    return recur();
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */