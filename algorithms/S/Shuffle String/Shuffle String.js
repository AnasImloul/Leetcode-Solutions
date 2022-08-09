var restoreString = function(s, indices) {
    const result = []
    
    for(let i=0; i<s.length; i++) {
        const letter = s[i]
        const index = indices[i]
        result[index] = letter
    }
    
    return result.join('')
};
