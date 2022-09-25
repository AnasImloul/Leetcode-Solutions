// Runtime: 4252 ms (Top 41.99%) | Memory: 42.1 MB (Top 50.71%)
    /**
 * @param {number} num
 * @return {boolean}
 */
var checkPerfectNumber = function(num) {
    let total = 0

    for(let i = 1 ; i < num;i++){
        if(num % i == 0){
            total += i
        }
    }
    return total == num ? true : false
};