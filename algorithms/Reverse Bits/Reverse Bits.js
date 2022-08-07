/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */

// remember the binary must always be of length 32 ;);
var reverseBits = function(n) {
    const reversedBin = n.toString(2).split('').reverse().join('');
    const result =  reversedBin.padEnd(32,'0'); 
    return parseInt(result, 2);
};
