var maximumGain = function(s, x, y) {
    const n = s.length;
    
    let totPoints = 0;
    let stack;
    
    if (x > y) {
        stack = remove(s, x, "ab");
        s = stack.join("");
        remove(s, y, "ba");
        
    }
    else {
        stack = remove(s, y, "ba");
        s = stack.join("");
        remove(s, x, "ab");
    }
    
    return totPoints;
    
    
    function remove(str, points, match) {
        const stack = [];
        
        for (let i = 0; i < str.length; i++) {
            const char = str.charAt(i);
            
            if (stack.length > 0 && stack[stack.length - 1] + char == match) {
                totPoints += points;
                stack.pop();
            }
            else {
                stack.push(char);
            }
        }
        
        return stack;
    }
};
