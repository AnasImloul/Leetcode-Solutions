// Runtime: 119 ms (Top 50.88%) | Memory: 45 MB (Top 5.70%)
var divide = function(dividend, divisor) {
    if (dividend == -2147483648 && divisor == -1) return 2147483647;
    let subdividend = Math.abs(dividend)
    let subdivisor = Math.abs(divisor)
    let string_dividend = subdividend.toString()
    let i = 0
    let ans=0
    let remainder = 0
    while(i<string_dividend.length){
        remainder =remainder*10+Number(string_dividend[i])
        let quotient = Math.floor(remainder/subdivisor)
        ans = ans *10 + quotient
        remainder = remainder - quotient*subdivisor
        i++;
    }
    if((dividend >0 && divisor <0) || (dividend <0 && divisor >0)) return 0-ans
    return ans
};