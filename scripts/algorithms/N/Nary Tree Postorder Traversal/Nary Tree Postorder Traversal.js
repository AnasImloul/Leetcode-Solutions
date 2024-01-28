// Runtime: 67 ms (Top 68.53%) | Memory: 52.70 MB (Top 12.35%)

/**
 * @param {Node} root
 * @return {number[]}
 */
var postorder = function(root) {
    const res = [];
    traverse(root);
    return res;
    
    function traverse(node) {
        if (!node) return;
        for(child of node.children) {
            traverse(child);
        }
        res.push(node.val);
    } 
};
