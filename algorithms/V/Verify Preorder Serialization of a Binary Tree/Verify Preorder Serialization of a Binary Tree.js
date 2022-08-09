var isValidSerialization = function(preorder) {
    preorder = preorder.split(',');
    const len = preorder.length;
    const stack = [];
    for(let i = len - 1; i >= 0; i--) {
        if(preorder[i] == '#') stack.push('#');
        else {
            if(stack.length < 2) return false;
            if(stack.at(-1) != '#' || stack.at(-2) != '#') return false;
            stack.pop();
        }
    }
    
    return stack.length == 1 && stack[0] == '#';
};
