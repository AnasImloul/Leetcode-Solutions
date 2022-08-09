/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
let sumArray = (arr) => {
    return arr.reduce((prev, curr) => prev + curr, 0)
}

var distanceBetweenBusStops = function(distance, start, destination) {
    let dist = sumArray(distance.slice((start < destination)?start:destination, (start < destination)?destination:start));
    return Math.min(dist, sumArray(distance) - dist)
};