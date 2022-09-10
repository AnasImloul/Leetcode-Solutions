// Runtime: 1161 ms (Top 6.67%) | Memory: 64.8 MB (Top 17.78%)
var maximumBags = function(capacity, rocks, additionalRocks) {
    var differences = []
    var count = 0
    for (let i in rocks) {
        if ((capacity[i] - rocks[i]) > 0) { // check if rocks[i] is less than capacity[i]
            differences.push(capacity[i] - rocks[i]) // add the difference
        } else {
            count++ // rocks[i] is at full capacity, so the result goes up by 1
        }
    }
    differences.sort((a, b) => a-b) // sort the differences
    var r = additionalRocks
    while (r != 0 && differences.length > 0) { // loop through differences until there is no more rocks or all of the bags of rocks are at full capacity
        if (differences[0] <= r) {
            r -= differences[0] // minus the difference of the rocks
            count++ // add to result because another bag of rocks is at full capacity
        } else {
            break // rocks can not make any other bags at full capacity, so stop right here
        }
        differences.shift() // remove the first difference
    } return count
}