/**
 * @param {number} n
 * @return {number}
 */
var numberOfMatches = function(n) {
    let matches = 0,current = n;
    while(current > 1){
        if(current % 2 === 0){
            matches += current/2;
            current = current/2
        }else{
            matches += (current-1)/2;
            current = (current-1)/2 + 1 ;
        }
    }
    return matches;
};

