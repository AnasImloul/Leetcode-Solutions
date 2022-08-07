var isSameTree = function(p, q) {
    
    const stack = [p, q];
    
    while (stack.length) {
        const node2 = stack.pop();
        const node1 = stack.pop();
        
        if (!node1 && !node2) continue;

        if (!node1 && node2 || node1 && !node2 || node1.val !== node2.val) {
            return false;
        }
        
        stack.push(node1.left, node2.left, node1.right, node2.right);
    }
    
    return true;
};
