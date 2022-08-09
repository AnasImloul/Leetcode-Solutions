var makeFancyString = function(s) {
    let res = '';
    let currCount = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (currCount === 2 && s[i] === s[i - 1]) continue;
        
        else if (s[i] === s[i - 1]) {
            currCount++;
            res += s[i];
        }
        
        else {
            currCount = 1;
            res += s[i]
        }
    }
    
    return res;
};
