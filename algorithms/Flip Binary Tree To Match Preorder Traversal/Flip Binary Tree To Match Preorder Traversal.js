var flipMatchVoyage = function(root, voyage) {
    const output = []
    let idx = 0;
    
    function run(node) {
        if(!node) return true;
        if(voyage[idx] !== node.val) return false;
        idx++;
        
        if(node.left && node.left.val !== voyage[idx]) {
            output.push(node.val);
            return run(node.right) && run(node.left);
        }
        return run(node.left) && run(node.right);
    }
    return run(root) ? output : [-1];
};
