// Runtime: 106 ms (Top 46.81%) | Memory: 44 MB (Top 75.83%)
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    for(let i=0 ; i<flowerbed.length ; i++) {
        if((i===0 || flowerbed[i-1]===0) && flowerbed[i]===0 && (i===flowerbed.length-1 || flowerbed[i+1]===0)) {
            flowerbed[i]=1;
            n--;
        }
    }
    return n < 1;
};