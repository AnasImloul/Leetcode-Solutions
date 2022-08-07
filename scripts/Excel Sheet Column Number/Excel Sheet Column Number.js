/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    /*
        one letter: result between 1-26.
        two letter: result between 26^1 + 1 -> 26^2 + digit. 27 - 702. All the combinations of A-Z and A-Z. 
    */
    
    let sum = 0;
    for (let letter of columnTitle) {
        let d = letter.charCodeAt(0) - 'A'.charCodeAt(0) + 1;
        sum = sum * 26 + d;
    }
    
    return sum;
};
