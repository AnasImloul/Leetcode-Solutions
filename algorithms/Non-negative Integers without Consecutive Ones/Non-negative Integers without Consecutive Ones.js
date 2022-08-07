var findIntegers = function(n) {
    let dp = len=>{
        if (len<0)
            return 0;
        if (!len)
            return 1;
        let _0x = 1; // number of accepted combination when '1' is first
        let _1x = 1; // number of accepted combination when '0' is first
        while (--len)
            [_0x, _1x] = [_0x+_1x, _0x];
        return _0x + _1x;
    };
    let binary = n.toString(2);
    let count = 0;
    let is_prev_one = false;
    for (let i = 0; i<binary.length; i++) {
        if (binary[i] === '0') {
            is_prev_one = false;
            continue;
        }
        count += dp(binary.length-i-1);
        if (is_prev_one)
            return count;
        is_prev_one = true;
    }
    return count + 1;
};
