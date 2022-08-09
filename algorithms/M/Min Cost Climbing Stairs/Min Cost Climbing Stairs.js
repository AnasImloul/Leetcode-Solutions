var minCostClimbingStairs = function(cost) {
    //this array will be populated with the minimum cost of each step starting from the top
    let minCostArray = [];
    //append a 0 at end to represent reaching the 'top'
    minCostArray[cost.length] = 0;
    //append the last stair to the end of the array
    minCostArray[cost.length - 1] = cost[cost.length - 1];
    
    //starts at -2 the length since we already have two elements in our array
    for (let i = cost.length - 2; i > -1; i--) {
        //checks which minimum cost is lower and assigns the value at that index accordingly
        if (minCostArray[i + 1] < minCostArray[i + 2]) minCostArray[i] = cost[i] + minCostArray[i + 1];
        else minCostArray[i] = cost[i] + minCostArray[i + 2];
    }
    //checks which of the first two options is the lowest cost
    return minCostArray[0] > minCostArray[1] ? minCostArray[1] : minCostArray[0];
};
