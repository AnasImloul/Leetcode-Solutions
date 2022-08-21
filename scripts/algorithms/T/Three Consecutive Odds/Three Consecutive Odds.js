// Runtime: 82 ms (Top 63.89%) | Memory: 42.1 MB (Top 58.33%)

var threeConsecutiveOdds = function(arr) {
    let c = 0;

    for(let val of arr){
        if(val % 2 === 1){
            c++;
            if(c === 3) {
                return true;
            }
        } else {
            c=0;
        }
    }

    return false;
};