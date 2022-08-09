var minEatingSpeed = function(piles, h) {
    let low = 1, high = Math.max(...piles)
    let minBanana = Infinity
    while(low <= high){
        const banana = Math.floor((high - low) / 2) + low
        const hours = piles.reduce((a, c) => a + Math.ceil(c / banana), 0)
        if(hours <= h){
            minBanana = banana
            high = banana - 1
        }
        else low = banana + 1
    }
    return minBanana
};
// time O(nlog(max(banana)), space O(1) 
