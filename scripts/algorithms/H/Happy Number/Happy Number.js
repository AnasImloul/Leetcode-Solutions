// Runtime: 121 ms (Top 23.03%) | Memory: 43.2 MB (Top 71.09%)
var isHappy = function(n) {
    if(n<10){
        if(n === 1 || n === 7){
            return true
        }
        return false
    }
    let total = 0
    while(n>0){
        let sq = n % 10
        total += sq**2
        n -= sq
        n /= 10
    }
    if(total === 1){
        return true
    }
    return isHappy(total)
};