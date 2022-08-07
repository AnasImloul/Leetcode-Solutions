var preorderTraversal = function(root) {
    let res = []
    
    const check = node => {
        if(node === null) return
        else res.push(node.val)
        
        if(node.left !== null) check(node.left)
        if(node.right !== null) check(node.right)
    }
    
    check(root)
    
    return res
};
