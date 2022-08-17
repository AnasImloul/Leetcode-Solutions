var maximumNumber = function(num, change) {
    const digits = num.split("");
    
    let started = false;
    
    for (let i = 0; i < digits.length; ++i) {
        const origDig = digits[i];
        const changeDig = change[origDig];
        
        if (changeDig > origDig) {
            started = true;
            digits[i] = changeDig;
        }
        else if (changeDig < origDig && started) {
            break;
        }
    }
    
    return digits.join(""); 
};
