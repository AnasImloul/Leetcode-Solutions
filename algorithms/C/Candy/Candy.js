/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
    const n = ratings.length;    
    
    let candies = [...Array(n)].fill(1);
 
    let index = 0;
    let copy = [ratings[0]];
    
    let isDecreasing = true;
    for(let i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            isDecreasing = false;
            break;
        }
        /* In case of decreasing sequence, make a copy of the current rating, but in inverted format */
        copy.unshift(ratings[i]);
    }
    
    if (isDecreasing) {
        ratings = copy;
    } else {
        copy = [];
    }
    
    while(index >= 0) {
        
        if (index >= n) {
            break;
        }

        if (ratings[index] > ratings[index + 1] && candies[index + 1] >= candies[index]) {            
            candies[index] = candies[index] + 1;            
            index = Math.max(-1, index - 2);
        }
        else if (ratings[index] > ratings[index - 1] && candies[index - 1] >= candies[index]) {            
            candies[index] = candies[index - 1] + 1;
        }

        index++;
     }

    
    return candies.reduce((sum, candy) => sum + candy, 0);
}
