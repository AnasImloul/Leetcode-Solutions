var braceExpansionII = function(expression) { // , mutiplier = ['']
    const char = ('{' + expression + '}').split('').values()
    const result = [...rc(char)];
    result.sort((a,b) => a.localeCompare(b));
    return result;
};

function rc (char) {
    const result = new Set();  
    
    let resolved = ['']
    let chars = '';
    let currentChar = char.next().value; 
   
    while (currentChar !== '}' && currentChar) {
        if (currentChar === '{') {
            resolved = mix(mix(resolved, [chars]), rc(char));
            chars = '';
        } else if (currentChar === ',') {
            for (const v of mix(resolved, [chars])) {
                result.add(v);
            }
            chars = '';
            resolved = [''];
        } else {
            chars += currentChar;
        }
        currentChar = char.next().value;
    }
    
    for (const v of mix(resolved, [chars])) {
        result.add(v);
    }
    
    return result; // everything
}

function mix (a, b) {
    const result = [];
    for (const ca of a) {
        for (const cb of b) {
            result.push(ca + cb);
        }
    }
    return result;
}
