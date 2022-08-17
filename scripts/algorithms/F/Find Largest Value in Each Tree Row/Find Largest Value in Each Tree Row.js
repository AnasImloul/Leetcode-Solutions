var largestValues = function(root) {
    if(!root) return [];
    
    const op = [];
    const Q = [[root, 1]];
    while(Q.length) {
        const [r, l] = Q.shift();
        
        if(op.length < l) op.push(-Infinity);
        op[l-1] = Math.max(op[l-1], r.val);
        
        if(r.left) Q.push([r.left, l + 1]);
        if(r.right) Q.push([r.right, l + 1]);
    }
    return op;
};
