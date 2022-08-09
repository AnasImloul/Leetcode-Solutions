var maxCoins = function(piles) {
    let count = 0, i = 0, j = piles.length - 1;
    piles.sort((a, b) => b - a);
    
    while(i < j) {
        count += piles[i + 1];
        i += 2;
        j--;
    }
    
    return count;
};
