// Runtime: 49 ms (Top 69.44%) | Memory: 41.50 MB (Top 75.0%)

/**
 * @param {number} length
 * @param {number} width
 * @param {number} height
 * @param {number} mass
 * @return {string}
 */
var categorizeBox = function(length, width, height, mass) {
    let isBulky = false
    let isHeavy = false
    
    if(length >= 10**4) isBulky = true
    if(width >= 10**4) isBulky = true
    if(height >= 10**4) isBulky = true
    if(length * width * height >= 10**9) isBulky = true

    if(mass >= 100) isHeavy = true

    if(isBulky && isHeavy) return 'Both'
    if(!isBulky && !isHeavy) return 'Neither'
    if(isBulky && !isHeavy) return 'Bulky'
    if(!isBulky && isHeavy) return 'Heavy'

};
