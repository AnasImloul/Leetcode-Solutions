var averageOfSubtree = function(root) {
    let count = 0;
    
    function traverse(node) {
        if (node === null) {
            return [0, 0];
        }

        let [sumLeft, countLeft] = traverse(node.left);
        let [sumRight, countRight] = traverse(node.right);

        if (Math.floor((sumLeft + sumRight + node.val) / (countLeft + countRight + 1)) === node.val) {
            count++;
        }

        return [sumLeft + sumRight + node.val, countLeft + countRight + 1];
    }
    
    traverse(root);
    
    return count;
};
