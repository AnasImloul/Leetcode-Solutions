var fractionToDecimal = function(numerator, denominator) {
    if(numerator == 0) return '0'
    let result = ''
    if(numerator*denominator <0){
        result += '-'
    }
    
    let dividend = Math.abs(numerator)
    let divisor = Math.abs(denominator)
    result += Math.floor(dividend/divisor).toString()
    
    let remainder = dividend % divisor
    if(remainder == 0) return result
    
    result += '.'
    
    let map1 = new Map()
    while(remainder != 0){
        if(map1.has(remainder)){
            let i = map1.get(remainder)
            result = result.slice(0, i) + '(' + result.slice(i) + ')'
            break;
        }
        map1.set(remainder, result.length)
        remainder *= 10
        result += Math.floor(remainder/divisor).toString()
        remainder %= divisor
    }
    return result
};
