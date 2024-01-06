// Runtime: 177 ms (Top 62.5%) | Memory: 52.70 MB (Top 41.67%)

/**
 * @param {number[]} price
 * @param {number} k
 * @return {number}
 */
var maximumTastiness = function(price, k) {
    const N = price.length
    price.sort((a,b) => a - b)
    let left = 0
    let right = price.at(-1)-price[0] + 1 
    while(left < right) {
        const mid = Math.floor(left + (right-left)/2)
        if(!condition(mid)) {
            right = mid
        } else {
            left = mid +1
        }
    }
    return left -1 
    
    function condition(mid) {
        let first = price[0]
        let count = 1
        for(let i = 1; i <N; i++) {
            if(price[i]-first>=mid) {
                count++
                first = price[i]
            }
            if(count===k) return true
        }
        return false
    }
};
