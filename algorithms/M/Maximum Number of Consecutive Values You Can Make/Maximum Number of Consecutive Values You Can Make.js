// we iterate from the smallest number while maintaining an integer sum. sum means that we can produce all number from 0 to sum.
// when we can make numbers from 0 to sum, and we encounter a new number, lets say arr[2].
// it is obvious that we can create all numbers from sum to sum + arr[2].
// if there is a gap if(arr[i] > sum+1) it means no combinations could create that number and we stop.
var getMaximumConsecutive = function(coins) {
    coins.sort((a,b) => a-b);
    let sum = 1;
    for(let i = 0; i < coins.length; i++) {
        if(coins[i] <= sum) {
            sum += coins[i];
        } else {
            break;
        }
    }
    return sum;
};
