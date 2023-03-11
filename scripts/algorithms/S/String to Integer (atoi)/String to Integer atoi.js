const toNumber = (s) => {
    let res = 0;
    for (let i = 0; i < s.length; i++) {
        res = res * 10 + (s.charCodeAt(i) - '0'.charCodeAt(0));
    }
    
    return res
}

var myAtoi = function(s) {
    s = s.trim();
    let r = s.match(/^(\d+|[+-]\d+)/);
    
    if (r) {
        let m = r[0], res;
        switch (m[0]) {
            case "-":
                res = toNumber(m.slice(1)) * -1;
                break;
            case '+':
                res = toNumber(m.slice(1));
                break;
            default:
                res = toNumber(m);
                break;
        }
        
        if (res < (1 << 31)) return (1 << 31);
        if (res > -(1 << 31) - 1) return -(1 << 31) - 1;
        return res;
    }
    
    return 0;
};