// Runtime: 132 ms (Top 31.75%) | Memory: 45.5 MB (Top 21.64%)
function isNum(ch){
    return !Number.isNaN(parseInt(ch));
}
var myAtoi = function(s) {
    let index = 0;

    // Remove whitespace
    while(index < s.length && s[index] === ' '){
        index++;
    }

    // Get the multiplier.
    const MULTIPLIER = index < s.length && s[index] === '-' ? -1: 1;

    // If the starting index is a sign char then move to the next character.
    if(index < s.length && (s[index] === '-' || s[index] === '+')){
        index++;
    }

    // Remove all leading zeros.
    while(index < s.length && s[index] === '0'){
        index++;
    }

    const MIN_NEG_INT = Math.pow(-2,31);
    const MAX_POS_INT = (MIN_NEG_INT + 1) * -1;

    // Get the first sequence number in the string.
    let num = 0;
    while(index < s.length && isNum(s[index])){
        let digit = parseInt(s[index]);
        if(num > Math.floor((MAX_POS_INT - digit)/10)){
            // Handle overflow.
            if(MULTIPLIER === 1){
                return MAX_POS_INT;
            }else{
                return MIN_NEG_INT;
            }
        }
        num = num * 10 + parseInt(s[index]);
        index++;
    }

    return num * MULTIPLIER;
};