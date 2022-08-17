var minimumWhiteTiles = function(floor, numCarpets, carpetLen) {
    let answer = Number.MAX_SAFE_INTEGER, dp = {};
    
    floor = floor.split('');
    
    function findMaxCoveredTiles(index, carpetsLeft) {
        if(index >= floor.length) {
            return 0;
        }
        if(dp[index]) {
            if(dp[index][carpetsLeft] != undefined) {
                return dp[index][carpetsLeft];
            }
        }
        else {
            dp[index] = {};
        }
        
        dp[index][carpetsLeft] = Number.MIN_SAFE_INTEGER;
        if(carpetsLeft) {
            dp[index][carpetsLeft] = Math.min(carpetLen, floor.length - index) + findMaxCoveredTiles(index + carpetLen, carpetsLeft - 1);
        }

        dp[index][carpetsLeft] = Math.max(dp[index][carpetsLeft], !+floor[index] + findMaxCoveredTiles(index + 1, carpetsLeft));
        
        return dp[index][carpetsLeft];
    }
    
    return floor.length - findMaxCoveredTiles(0, numCarpets);
};
