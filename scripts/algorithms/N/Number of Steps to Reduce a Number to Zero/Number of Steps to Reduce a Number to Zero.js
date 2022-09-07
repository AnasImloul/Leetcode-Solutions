// Runtime: 97 ms (Top 35.24%) | Memory: 41.7 MB (Top 89.00%)
var numberOfSteps = function(num) {
    let steps = 0
    while (num > 0) {
        if (num % 2 === 0) {
            num = num/2
            steps++
        }

        if (num % 2 === 1) {
            num--
            steps++
        }
    }

    return steps

};