// Runtime: 192 ms (Top 23.33%) | Memory: 55.3 MB (Top 40.00%)

var numberOfWeeks = function(milestones) {
    let maxElement = 0,arraySum = 0;

    for(let milestone of milestones){
        arraySum += milestone;
        maxElement = Math.max(maxElement,milestone);
    }

    let rest = arraySum - maxElement;
    let difference = maxElement - rest;

    if(difference <= 1) return arraySum;

    return (arraySum - difference) + 1;
};