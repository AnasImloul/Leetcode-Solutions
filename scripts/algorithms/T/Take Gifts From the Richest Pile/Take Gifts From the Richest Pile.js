// Runtime: 67 ms (Top 83.7%) | Memory: 42.62 MB (Top 82.1%)

/**
 * @param {number[]} gifts
 * @param {number} k
 * @return {number}
 */
var pickGifts = function(gifts, k) {
    while(k-->0){
        let max=Math.max(...gifts)
        gifts[gifts.lastIndexOf(max)]=Math.floor(Math.sqrt(max))
    }
    return gifts.reduce((a,b)=>a+b,0)
};