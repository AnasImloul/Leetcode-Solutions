var reorderedPowerOf2 = function(n) {
    const orig = convert(n);
    
    let num = 1;
    
    while (num <= 1e9) {
        const str = convert(num);
        
        if (str === orig) return true;
        num <<= 1;
    }
    
    return false;
    
    function convert(num) {
        const str = num.toString();
        const digits = str.split("");
        const sort = digits.sort();
        return sort.join("#");
    }
};
