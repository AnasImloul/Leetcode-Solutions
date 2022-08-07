var countVowelPermutation = function(n) {
    let a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1000000007
    while(n-- > 1){
        let new_a = a % mod, new_e = e % mod, new_i = i % mod, new_o = o % mod, new_u = u % mod
        a = new_e + new_i + new_u
        e = new_a + new_i
        i = new_e + new_o
        o = new_i
        u = new_i + new_o
    }
    return (a + e + i + o + u) % mod
};
