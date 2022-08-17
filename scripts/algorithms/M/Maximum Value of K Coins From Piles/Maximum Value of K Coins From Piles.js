/**
 * @param {number[][]} piles
 * @param {number} k
 * @return {number}
 */
var maxValueOfCoins = function(piles, k) {
    var n = piles.length;
    var cache = {};
    
    var getMax = function(i, k) {
        if (i >= n || k <= 0) return 0;
        var key = i + ',' + k;
        if (cache[key] !== undefined) return cache[key];
        var ans = getMax(i + 1, k);
        var cur = 0;
        
        for (var j = 0; j < piles[i].length && j < k; j++) {
            cur+=piles[i][j];
            ans = Math.max(ans, cur + getMax(i + 1, k - j - 1));
        }
        
        return cache[key] = ans;
    }
    
    return getMax(0, k);
};
