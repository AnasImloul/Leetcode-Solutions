// Runtime: 161 ms (Top 67.20%) | Memory: 49.7 MB (Top 36.80%)
var removeInvalidParentheses = function(s) {
    const isValid = (s) => {
        const stack = [];
        for(let c of s) {
            if(c == '(') stack.push(c);
            else if(c == ')') {
                if(stack.length && stack.at(-1) == '(')
                    stack.pop();
                else return false;
            }
        }
        return stack.length == 0;
    }

    const Q = [s], vis = new Set([s]), ans = [];
    let found = false;
    while(Q.length) {
        const top = Q.shift();
        if(isValid(top)) {
            ans.push(top);
            found = true;
        }
        if(found) continue;
        for(let i = 0; i < top.length; i++) {
            if(!'()'.includes(top[i])) continue;

            const str = top.slice(0, i) + top.slice(i + 1);
            if(!vis.has(str)) {
                Q.push(str);
                vis.add(str);
            }
        }
    }
    if(ans.length == 0) return [''];
    return ans;
};