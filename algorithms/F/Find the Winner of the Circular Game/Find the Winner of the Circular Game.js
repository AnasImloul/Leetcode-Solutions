/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {
    let friends = Array.from({length: n}, (_, index) => index + 1)
    let start = 0;
    while(friends.length != 1){
        start += (k - 1)
        start = start % friends.length
        friends.splice(start,1)
    }
    return friends[0]
};
