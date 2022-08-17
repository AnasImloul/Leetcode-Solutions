var maxValue = function(n, x) {
    let i;

    // if the number if positive, find the first
    // number that is less than x
    if (n[0] !== '-') {
        for (i = 0; i < n.length; i++) {
            if (Number(n[i]) < x) break;
        }        
    
    // if the number is negative, find the first
    // number that is greater than x
    } else {
        for (i = 1; i < n.length; i++) {
            if (Number(n[i]) > x) break;
        }
    }
    
    // return the string with x inserted at the found index
    return n.slice(0, i) + x + n.slice(i)
};


///////////////// short hand ////////////////////


var maxValue = function(n, x) {
    let i;
    if (n[0] !== '-') {
        for (i = 0; i < n.length; i++) {
            if (Number(n[i]) < x) break;
        }        
    } else {
        for (i = 1; i < n.length; i++) {
            if (Number(n[i]) > x) break;
        }
    }
    return n.slice(0, i) + x + n.slice(i)
};
