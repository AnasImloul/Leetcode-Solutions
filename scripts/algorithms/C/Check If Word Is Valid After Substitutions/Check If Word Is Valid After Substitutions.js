// Runtime: 105 ms (Top 65.38%) | Memory: 45.6 MB (Top 59.62%)

var isValid = function(s) {
    const stack = [];
    for(let c of s) {
        if(c !== 'c') {
            stack.push(c);
        }else {
            if(stack.pop() !== 'b') return false;
            if(stack.pop() !== 'a') return false;
        }
    }

    return stack.length === 0;
};