// Runtime: 134 ms (Top 91.67%) | Memory: 59.20 MB (Top 25.0%)

var getMaximumConsecutive = function(coins) {
    coins.sort((a, b) => a - b);
    let maxConsec = 1;
    
    for(let num of coins) {
        if(num <= maxConsec) maxConsec += num;
    }
    return maxConsec;    
};
