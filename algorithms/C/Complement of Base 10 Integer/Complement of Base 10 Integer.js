var bitwiseComplement = function(n) {
    let xor = 0b1;
    let copy = Math.floor(n / 2);
    while (copy > 0) {
        xor = (xor << 1) + 1
        copy = Math.floor(copy / 2);
    }
        
    return n ^ xor;
};
