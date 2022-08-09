/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function(jewels, stones) {
    const jewelsCountObj = {};
    let jewelsCount = 0;
    
    for (const i of jewels) {
        jewelsCountObj[i] = 0;
    }
    
    for (const i of stones) {
        if (jewelsCountObj[i] >= 0) jewelsCountObj[i] += 1;
    }

    for (const i in jewelsCountObj) {
        jewelsCount += jewelsCountObj[i];
    }
    
    return jewelsCount;
};

