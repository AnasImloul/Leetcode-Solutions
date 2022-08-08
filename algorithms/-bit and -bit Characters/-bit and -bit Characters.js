/**
 * @param {number[]} bits
 * @return {boolean}
 */
var isOneBitCharacter = function(bits) {
    let len = bits.length;
    if(len===1) return true;
    if (bits[len - 1] === 1)  return false;
    let i=0;
    while(i<len-1){
        if(bits[i]===0) i+=1;
        else i+=2;
    }
    if(i===len-1) return true;
    return false;
};
