// Runtime: 53 ms (Top 61.16%) | Memory: 45.00 MB (Top 12.4%)

var removeOccurrences = function(s, part) {
    let stack = [];
    for(let c of s) {
        stack.push(c);
        if(stack.length >= part.length && stack[stack.length-1] == part[part.length-1]) {
            let temp = [];
            for(let i = 0; i < part.length; i++) {
                temp.push(stack.pop());
            }
            temp.reverse();
            if(temp.join('') != part) {
                for(let c of temp) {
                    stack.push(c);
                }
            }
        }
    }
    let ans = [];
    while(stack.length > 0) {
        ans.push(stack.pop());
    }
    ans.reverse();
    return ans.join('');
};
