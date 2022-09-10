// Runtime: 93 ms (Top 44.76%) | Memory: 41.9 MB (Top 75.92%)
var largestAltitude = function(gain) {
    let points = [0]
    let highest = 0

    for (let i = 0; i < gain.length; i++) {
        let point = points[i] + gain[i]
        points.push(point)
        if (point > highest) highest = point
    }

    return highest
};