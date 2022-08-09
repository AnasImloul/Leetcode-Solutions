var minFlips = function(a, b, c) {
    let ans = 0;
    for(let bit = 0; bit < 32; bit++) {
        let bit_a = (a >> bit)&1, bit_b = (b >> bit)&1, bit_c = (c >> bit)&1;
        if(bit_c !== (bit_a | bit_b)) {
            if(bit_c === 1) { //a b will be 0 0
                ans += 1;
            } else { //a b -> 0 1 -> 1 0 -> 1 1
                ans += (bit_a + bit_b === 2 ? 2 : 1);
            }
        }
    }
    return ans;
};
