const mod = (10 ** 9) + 7
var countHousePlacements = function(n) {
    let prev2 = 1
    let prev1 = 1
    let ways = 2
    
    for ( let i = 2; i <= n; i++ ) {
        prev2 = prev1
        prev1 = ways
        ways = ( prev1 + prev2 ) % mod
    }
    
    return (ways ** 2) % mod
}
