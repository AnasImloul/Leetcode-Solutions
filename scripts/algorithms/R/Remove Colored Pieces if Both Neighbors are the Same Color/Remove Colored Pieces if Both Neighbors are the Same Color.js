var winnerOfGame = function(colors) {
    const n = colors.length;
    const stack = [];
    
    let alice = 0;
    let bob = 0;
    
    for (let i = 0; i < n; ++i) {
        const char = colors[i];
        
        if (stack.length > 1 && stack[stack.length - 1] === char && stack[stack.length - 2] === char) {
            stack.pop();
            
            if (char === "A") ++alice;
            else ++bob;
        }
        stack.push(char);
    }
    
    return alice > bob ? true : false; 
};
