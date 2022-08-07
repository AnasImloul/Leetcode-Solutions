var removeKdigits = function(num, k) {
    if(k == num.length) {
        return '0'
    }
    let stack = []
    for(let i = 0; i < num.length; i++) {
        while(stack.length > 0 && num[i] < stack[stack.length - 1] && k > 0) {
            stack.pop()
            k--
        }
        stack.push(num[i])
    }
    while(k > 0) {
        stack.pop()
        k--
    }
    while(stack[0] == 0 && stack.length > 1) {
        stack.shift()
    }
    return stack.join('')
}
