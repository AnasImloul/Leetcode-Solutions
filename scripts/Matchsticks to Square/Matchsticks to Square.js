var makesquare = function(matchsticks) {
    const perimeter = matchsticks.reduce((a, b) => a + b, 0);
    if(perimeter % 4 != 0 || matchsticks.length < 4) return false;
    
    const sideLen = perimeter / 4;
    // find a way to divide the array in 4 group of sum side length
    const sides = new Array(4).fill(0);
    const len = matchsticks.length;
    matchsticks.sort((a, b) => b - a);
    
    const solve = (x = 0) => {
        if(x == len) {
            return sides.every(side => side == sideLen);
        }
        
        for(let i = 0; i < 4; i++) {
            if(sides[i] + matchsticks[x] > sideLen) {
                continue;
            }
            sides[i] += matchsticks[x];
            if(solve(x + 1)) return true;
            sides[i] -= matchsticks[x];
        }
        return false;
    }
    return solve();
};
