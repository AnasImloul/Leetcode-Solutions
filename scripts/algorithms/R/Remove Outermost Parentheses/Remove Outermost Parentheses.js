var removeOuterParentheses = function(s) {
    let open = -1, ans = "", stack = [];
    for(let c of s) {
        if(c == '(') {
            // open for top level open
            if(open != -1) ans += c;
            stack.push(open)
            open++;
        } else {
            open = stack.pop();
            // close for top level open
            if(open != -1) ans += c;
        }
    }
    return ans;
};
