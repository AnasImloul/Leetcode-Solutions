// Runtime: 314 ms (Top 29.18%) | Memory: 50.3 MB (Top 91.06%)
var isPalindrome = function(x) {
    if(x < 0 || x % 10 === 0 && x !== 0) return false

    let num = x
    let rev_x = 0

    while(x > 0){
        let digit = Math.floor(x % 10)
        rev_x = Math.floor(rev_x * 10 + digit)
        x = Math.floor(x / 10)
    }
    return num === rev_x
};