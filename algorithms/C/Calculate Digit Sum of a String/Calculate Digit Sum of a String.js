var digitSum = function(s, k) {
    while (s.length > k) {
        let newString = "";
        for (let i = 0; i < s.length; i += k)
            newString += s.substring(i, i + k).split("").reduce((acc, val) => acc + (+val), 0);
        
        s = newString;
    }
    
    return s;
};
