var minAddToMakeValid = function(s) {
    let stack = []
    let count = 0
    for(let i=0;i<s.length;i++) {
        let ch = s[i]
        if(ch === '(') {
            stack.push(ch)
        } else {
            let top = stack.pop()
            if(top != '(') count++
        }
    }
    
    count += stack.length
    
    return count
};
