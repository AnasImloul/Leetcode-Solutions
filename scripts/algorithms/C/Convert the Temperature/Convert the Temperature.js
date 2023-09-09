// Runtime: 54 ms (Top 48.6%) | Memory: 41.61 MB (Top 71.0%)

/**
 * @param {number} celsius
 * @return {number[]}
 */
var convertTemperature = function(celsius) {
    let F = celsius*1.80+32.00;
    let K = celsius+273.15;
    
    return [K,F]
};