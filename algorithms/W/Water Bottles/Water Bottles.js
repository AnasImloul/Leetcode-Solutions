var numWaterBottles = function(numBottles, numExchange) {
    let count = 0;
    let emptyBottles = 0;
    while (numBottles > 0) {
        count += numBottles;
        emptyBottles += numBottles;
        numBottles = Math.floor(emptyBottles / numExchange);
        emptyBottles -= numBottles  * numExchange;
    }
    
    
    return count;
};
