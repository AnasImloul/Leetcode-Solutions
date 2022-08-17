var addBinary = function(a, b) {
    let i = a.length-1, j = b.length-1, carry = 0
    let s =[]
    while(i >= 0 || j >= 0){
        let sum = carry
        if(i >= 0)  sum += a[i--].charCodeAt() - 48
        if(j >= 0)  sum += b[j--].charCodeAt() - 48
        s.unshift(sum % 2)
        carry = ~~(sum/2)
    }
    return carry > 0 ? "1" + s.join("") : s.join("")
};
