var diStringMatch = function(s) {
    let i = 0, d = s.length, arr = [];
    
    for(let j = 0; j <= s.length; j += 1) {
        if(s[j] === 'I') arr.push(i++);
        else arr.push(d--);
    }
    
    return arr;
};
