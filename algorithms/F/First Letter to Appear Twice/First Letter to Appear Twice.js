 var repeatedCharacter = function(s) {
    const m = {};
    
    for(let i of s) {
        if(i in m) {
            m[i]++
        } else {
            m[i] = 1
        }
        
        if(m[i] == 2) {
            return i
        }
    }
};